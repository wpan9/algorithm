// Given a list of functions, compute the estimated size of the module,
// In the sense of all functions are inlined. E.g.,
//
// A ----> B ----> C ---> D ---> F
//  \       \       \
//   \       \       \---> E
//    \       \
//     \       \---> C ---> D --> F
//      \             \
//       \----> F      \---> E
//
// sizeof(A) = size(A) + size(B) + 2 * size(C) + 2 * size(D) + 2 * size(E)
//             + 3 * size(F)
//
// A --> {size(A), B, F }
// B --> {size(B), C, C }
// C --> {size(C), D, E }
// D --> {size(D), F }
// E --> {size(E) }
// F --> {size(F) }
//
// A --> {size(A), B, F }
// B --> {size(B), C, C }
// C --> {size(C), D, E }
// D --> {size(D) + size(F) }
// E --> {size(E) }
// F --> {size(F) }
//
// A --> {size(A) + size(F), B }
// B --> {size(B), C, C }
// C --> {size(C) + size(E), D }
// D --> {size(D) + size(F) }
// E --> {size(E) }
// F --> {size(F) }
//
// A --> {size(A) + size(F), B }
// B --> {size(B), C, C }
// C --> {size(C) + size(E) + size(D) + size(F) }
// D --> {size(D) + size(F)}
// E --> {size(E) }
// F --> {size(F) }
//

unsigned computeSizeOfModule(llvm::Module *M)
{
    auto getSize = [](llvm::Function *F) {
        return std::acccumurate(F.begin(), F.end(), 0,
                              [](BasicBlock &BB) { return BB.size(); });
    };

    struct CallNode {
        unsigned Size;
        SmallVector<Function *, 8> Called;

        CallNode() : Size(0) {}
        bool isLeaf() const { return Called.empty(); }
    };

    SmallDenseMap<Function *, CallNode *> CG;

    // Initial the data structure.
    for (auto &F : M->getFunctionList())
    {
        if (F.empty()) continue;
        auto Node = new CallNode;
        Node->Size = getSize(F);
        CG[&F] = Node;
    }

    // This basically builds a call graph.
    for (auto &F : M->getFunctionList())
    {
        if (F.empty()) continue;

        CallNode *Node = CG[F];
        for (auto U: F.getUsers())
        {
            if (auto *CI = dyn_cast<CallInst>(U))
            {
                if (auto G = CI->getCalledFunction())
                {
                    Node->Called.push_back(G);
                }
            }
        }
    }

    // Iterate until all calls are resolved.
    while (true)
    {
        SmallVector<CallNode *, 8> LeafNodes;

        for (auto I = CG.begin(), E = CG.end(); I != E; ++I) {
            CallNode *CN = *I;
            if (Node->isLeaf())
            {
                LeafNodes.push_back(CN);
            }
        }

        if (LeaveNodes.empty())
            break;

        // Update
        for (auto I = LeafNodes.begin(), E = LeafNodes.end(); I != E; ++I)
        {

        }
    }
}

# Memory Analysis for C Variables and Functions

| Variable/Function | Segment | Sub-segment | Permissions | Lifetime |
|---|---|---|---|---|
| `g1`             | Data      | BSS        | Read-Write | Program   |
| `g2`             | Code      | rodata     | Read        | Program   |
| `g3`             | Data      | Data       | Read-Write | Program   |
| `g4`             | Data      | BSS        | Read-Write | Program   |
| `g5`             | Data      | Data       | Read-Write | Program   |
| `l1`             | Register  | None       | Read-Write | Function/Block |
| `l2`             | Data      | Stack      | Read-Write | Function/Block |
| `l3`             | Data      | Stack      | Read-Write | Function/Block |
| `f2`             | Data      | BSS        | Read-Write | Indefinite  |
| `f3`             | Data      | Stack      | Read-Write | Function/Block |
| `f4`             | Data      | Stack      | Read-Write | Function/Block |
| "Hello World!\n" | Code      | rodata     | Read        | Program   |
| `main()`         | Code      | Text       | Read        | Program   |
| `func()`         | Code      | Text       | Read        | Program   |
| `N`              | None      | None       | None        | None       |
| `*l2` (deref)   | Data      | Heap       | Read-Write | Indefinite  |
| `f1`             | Data      | Stack      | Read-Write | Function/Block |


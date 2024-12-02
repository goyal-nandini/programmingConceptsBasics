### Key Differences

| Feature               | `NULL`                     | `nullptr`                     |
|-----------------------|----------------------------|-------------------------------|
| **Type**              | Macro, typically `0`       | `std::nullptr_t`              |
| **Introduced In**     | C                          | C++11                         |
| **Type-Safe**         | No                         | Yes                           |
| **Overload Ambiguity**| Possible                  | Eliminated                    |
| **Convertible To**    | Integer or pointer types   | Only pointer types            |
| **Preferred**         | Legacy C/C++ code          | Modern C++ code               |

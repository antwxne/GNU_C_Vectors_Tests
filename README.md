# GNU Vectors examples

Some examples of [GNU Vectors](https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html)

## Example

```c
typedef int vector2D __attribute__((vector_size(sizeof(int) * 2)));
vector2D vector = {1, 3};
vector += 10;
// in this case vector will be equal to {11, 13}
```

## Tests

### Unit tests

Using [criterion unit testing framework](https://github.com/Snaipe/Criterion).

```shell
make tests_run
```

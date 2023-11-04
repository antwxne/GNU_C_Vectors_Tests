#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "vectors.h"

TestSuite(vector2D_op, .disabled = false);
TestSuite(vector2D_comp, .disabled = false);

Test(vector2D_op, add_with_int)
{
    vector2D vector = {1, 3};

    vector += 10;
    cr_expect(eq(vector[0], 1 + 10));
    cr_expect(eq(vector[1], 3 + 10));
}

Test(vector2D_op, sub_with_int)
{
    vector2D vector = {1, 3};

    vector -= 10;
    cr_expect(eq(vector[0], 1 - 10));
    cr_expect(eq(vector[1], 3 - 10));
}

Test(vector2D_op, mul_with_int)
{
    vector2D vector = {1, 3};

    vector *= 10;
    cr_expect(eq(vector[0], 1 * 10));
    cr_expect(eq(vector[1], 3 * 10));
}

Test(vector2D_op, div_with_int)
{
    vector2D vector = {1000, 30000};

    vector /= 10;
    cr_expect(eq(vector[0], 1000 / 10));
    cr_expect(eq(vector[1], 30000 / 10));
}

Test(vector2D_op, add_with_another_vector)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {18, -6};

    vector1 += vector2;
    cr_expect(eq(vector1[0], 1 + 18));
    cr_expect(eq(vector1[1], 3 + -6));
}

Test(vector2D_op, sub_with_another_vector)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {18, -6};

    vector1 -= vector2;
    cr_expect(eq(vector1[0], 1 - 18));
    cr_expect(eq(vector1[1], 3 - -6));
}

Test(vector2D_op, mul_with_another_vector)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {18, -6};

    vector1 *= vector2;
    cr_expect(eq(vector1[0], 1 * 18));
    cr_expect(eq(vector1[1], 3 * -6));
}

Test(vector2D_op, div_with_another_vector)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {18, -6};

    vector1 /= vector2;
    cr_expect(eq(vector1[0], 1 / 18));
    cr_expect(eq(vector1[1], 3 / -6));
}

Test(vector2D_comp, vectors_equal_true)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {1, 3};
    vector2D result;

    result = vector1 == vector2;
    cr_expect(eq(result[0], -1));
    cr_expect(eq(result[1], -1));
}

Test(vector2D_comp, vectors_equal_false)
{
    vector2D vector1 = {3, 9};
    vector2D vector2 = {1, 3};
    vector2D result;

    result = vector1 == vector2;
    cr_expect(eq(result[0], 0));
    cr_expect(eq(result[1], 0));
}

Test(vector2D_comp, vectors_equal_partialy_true)
{
    vector2D vector1 = {1, 3};
    vector2D vector2 = {1, 4};
    vector2D result;

    result = vector1 == vector2;
    cr_expect(eq(result[0], -1));
    cr_expect(eq(result[1], 0));
}
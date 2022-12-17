//3.Операции возведения в квадрат и извлечения корня.

float second_power(float x) {
  return x *= x;
}

float sq_root(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );
    return 1/y;
}

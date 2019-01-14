func1();
func2();
func3();

extern int v1, v2, v3;

int vm = 0;

main()
{
    printf("main, vm=%d, v1=%d, v2=%d, v3=%d\n",vm,v1,v2,v3);

    v1++;
    func1();

    v2++;
    func2();

    v3++;
    func3();

    return 0;
}
extern int vm, v2, v3;
int v1 = 1;

func1()
{
    static int fv1;
    return printf("f1, vm=%d, v1=%d, v2=%d, v3=%d\n",vm,v1,v2,v3);
}

extern int vm, v1, v3;
int v2 = 2;

func2()
{
    return printf("f2, vm=%d, v1=%d, v2=%d, v3=%d\n",vm,v1,v2,v3);
}

extern int vm, v1, v2;
int v3 = 3;

func3()
{
    return printf("f3, vm=%d, v1=%d, v2=%d, v3=%d\n",vm,v1,v2,v3);
}


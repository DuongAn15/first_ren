#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Bai1()
{
    printf("20235256 - Tran Duong An - 732726\nKtra: 10/01/2023\n");
    int n;
    do
    {
        scanf("%d", &n);
    } while (n <= 0 || n >= 10);

    float a[n], s = 0;
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            s += a[i];
    }
    printf("\nTong cac phan tu duong cua mang la: %f", s);
}

typedef struct
{
    float x;
    float y;
} Point;

float Kc(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float Area(Point a, Point b, Point c)
{
    float p;
    p = (Kc(a, b) + Kc(b, c) + Kc(c, a)) / 2;
    return sqrt(p * (p - Kc(a, b)) * (p - Kc(b, c)) * (p - Kc(c, a)));
}

int checkTri(Point a, Point b, Point c)
{
    if ((Kc(a, b) + Kc(b, c) == Kc(a, c)) ||
        (Kc(b, c) + Kc(c, a) == Kc(b, a)) ||
        (Kc(c, a) + Kc(a, b) == Kc(c, b)))
        return 0;
    return 1;
}
int checkQua(Point a, Point b, Point c, Point d)
{
    if (checkTri(a, b, c) && checkTri(b, c, d) && checkTri(c, d, a) && checkTri(d, a, b))
        return 1;
    return 0;
}

void Bai2()
{
    printf("20235256 - Tran Duong An - 732726\nKtra: 10/01/2023\n");
    Point A, B, C, D, M;
    printf("Nhap toa do diem A: ");
    scanf("%f%f", &A.x, &A.y);
    printf("Nhap toa do diem B: ");
    scanf("%f%f", &B.x, &B.y);
    printf("Nhap toa do diem C: ");
    scanf("%f%f", &C.x, &C.y);
    printf("Nhap toa do diem D: ");
    scanf("%f%f", &D.x, &D.y);
    printf("Nhap toa do diem M: ");
    scanf("%f%f", &M.x, &M.y);

    if (!checkQua(A, B, C, D))
        printf("Khong ton tai tu giac ABCD");
    else
    {
        float p4, s4, p3, s3;
        p4 = Kc(A, B) + Kc(B, C) + Kc(C, D) + Kc(D, A);
        p3 = Kc(M, C) + Kc(C, D) + Kc(D, M);
        s4 = Area(A, B, C) + Area(D, B, C);
        s3 = Area(M, C, D);

        if ((Kc(M, A) + Kc(M, B) == Kc(A, B)) ||
            (Kc(M, C) + Kc(M, B) == Kc(C, B)) ||
            (Kc(M, C) + Kc(M, D) == Kc(C, D)) ||
            (Kc(M, A) + Kc(M, D) == Kc(A, D)))
        {
            printf("Diem M nam tren bien tu giac ABCD");
        }
        else
        {
            if (Area(A, B, M) + Area(B, C, M) + Area(C, D, M) + Area(D, A, M) == s4)
                printf("Diem M nam trong tu giac ABCD");
            else
                printf("Diem M nam ngoai tu giac ABCD");
        }

        Point AB, BC, CD, DA;
        AB.x = B.x - A.x;
        AB.y = B.y - A.y;
        BC.x = C.x - B.x;
        BC.y = C.y - B.y;
        CD.x = D.x - C.x;
        CD.y = D.y - C.y;
        DA.x = A.x - D.x;
        DA.y = A.y - D.y;

        if ((Kc(A, B) == Kc(C, B)) &&
            (Kc(B, C) == Kc(C, D)) &&
            (Kc(D, C) == Kc(A, D)) &&
            AB.x * BC.x + AB.y * BC.y == 0)
            printf("\nTu giac ABCD la hinh vuong");
        else
        {
            if ((Kc(A, B) == Kc(C, B)) &&
                (Kc(B, C) == Kc(C, D)) &&
                (Kc(D, C) == Kc(A, D)))
                printf("\nTu giac ABCD la hinh thoi");

            if (AB.x * BC.x + AB.y * BC.y == 0 &&
                CD.x * BC.x + CD.y * BC.y == 0 &&
                CD.x * DA.x + CD.y * DA.y == 0)
                printf("\nTu giac ABCD la hinh chu nhat");
            else
            {
                if (((AB.x / CD.x == AB.y / CD.y) && (Kc(A, B) == Kc(C, D))) ||
                    ((BC.x / DA.x == BC.y / DA.y) && (Kc(B, C) == Kc(D, A))))
                    printf("\nTu giac ABCD la hinh binh hanh");
                else
                {
                    if ((CD.x == 0 && AB.x == 0) || (DA.x == 0 && BC.x == 0) ||
                        (CD.y == 0 && AB.y == 0) || (DA.y == 0 && BC.y == 0) ||
                        (AB.x / CD.x == AB.y / CD.y) || (BC.x / DA.x == BC.y / DA.y))
                    {
                        if (Kc(A, C) == Kc(B, D))
                            printf("\nTu giac ABCD la hinh thang can");
                        else if (AB.x * BC.x + AB.y * BC.y == 0 ||
                                 CD.x * BC.x + CD.y * BC.y == 0 ||
                                 CD.x * DA.x + CD.y * DA.y == 0 ||
                                 AB.x * DA.x + AB.y * DA.y == 0)
                            printf("\nTu giac ABCD la hinh thang vuong");
                        else
                            printf("\nTu giac ABCD la hinh thang");
                    }
                    else
                        printf("\nTu giac ABCD la Tu giac binh thuong");
                }
            }
        }

        printf("\nChu vi tu giac ABCD la: %f", p4);
        printf("\nDien tich tu giac ABCD la: %f", s4);
        if (checkTri(M, C, D) == 0)
            printf("\nKhong ton tai tam giac MCD");
        else
        {
            printf("\nChu vi tam giac MCD la: %f", p3);
            printf("\nChu vi tam giac MCD la: %f", s3);
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        Bai1();
        break;

    case 2:
        Bai2();
        break;

    default:
        break;
    }
    return 0;
}
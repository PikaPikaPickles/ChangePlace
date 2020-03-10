#include <iostream>

using namespace std;
class VectorN
{
public:
    unsigned int n;
    int *p = nullptr;
    // Конструктор вектора размерности n
    VectorN(unsigned int n){
        int *k = new int [n];
        this->n=n;
        this->p = k;
    };

    // Деструктор
    ~VectorN(){
        delete[] p;
    };

    // Получение размерности вектора
    unsigned int getSize() const{
        return n;
    };

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const{
        return p[i];
    };

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value){
        p[i] = value;

    };

    /*
     * Далее реализуйте перегруженные операторы
     */
    // Оператор == проверяет два вектора на равенство,
    // равны они, если строго равны всех их координаты
    bool operator==( VectorN& V1){
        for ( int i=0;i<n; i++ ){
            if (this->getValue(i) != V1.getValue(i)){
                return false;
            }
        }
        return true;
    }

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается

bool operator!=( VectorN& V1){
        for ( int i=0;i<n; i++ ){
            if (this->getValue(i) != V1.getValue(i)){
                return true;
            }
        }
        return false;
    }


    // Оператор + складывает два вектора покоординатно,
    // возвращает результат как новый экземпляр вектора
    VectorN operator+(VectorN& v2){
        VectorN v3 (v2.getSize());
        for ( int i=0; i < n; i++){
            v3.setValue(i,(p[i] + v2.getValue(i)));
            return v3;
        }
    }
    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    VectorN operator*(int a){
        VectorN v3 (n);
        for ( unsigned int i=0; i < n; i++){
            v3.setValue(i,(p[i] * a));
            return v3;
        }
    }

 friend VectorN operator*(int a, VectorN& v1){
        return v1*a;
    }
    // Умножение должно работать при любом порядке операндов.
};
int main()
{
 VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
    return 0;
}
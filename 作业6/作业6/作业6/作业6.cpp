
#include <iostream>

using namespace std;

int main()
{
    class Dot {
    private:
        int x, y, z;
    public:
        Dot(int xx, int yy, int zz) {
            x = xx; 
            y = yy; 
            z = zz;
        }
        Dot operator +(Dot next) {
            int nex = this->x + next.x;
            int ney = this->y + next.y;
            int nez = this->z + next.z;
            Dot newdo(nex, ney, nez);
            return newdo;
        }
        Dot operator -(Dot next) {
            int nex = this->x - next.x;
            int ney = this->y - next.y;
            int nez = this->z - next.z;
            Dot newdo(nex, ney, nez);
            return newdo;
        }
        void operator =(Dot next) {
            this->x = next.x;
            this->y = next.y;
            this->z = next.z;
        }
        Dot operator ++(int) {
            this->x++;
            this->y++;
            this->z++;
            return *this;
        }
        Dot operator --(int) {
            this->x--;
            this->y--;
            this->z--;
            return *this;
        }
        int operator [](int a) {
            if (a == 0) return this->x;
            if (a == 1) return this->y;
            if (a == 2) return this->z;
        }
    };
    int x, y, z;
    cout << "input dot 1:";
    cin >> x >> y >> z;
    Dot adot(x, y, z);
    cout << "input dot 2:";
    cin >> x >> y >> z;
    Dot bdot(x, y, z);
    Dot cdot(0,0,0);
    cout << "+\n";
    cdot = adot + bdot;
    cout << cdot[0] << " " << cdot[1] << " " << cdot[2] << endl;
    cdot = adot - bdot;
    cout << "-\n";
    cout << cdot[0] << " " << cdot[1] << " " << cdot[2] << endl;
    adot++;
    cout << "a++\n";
    cout << adot[0] << " " << adot[1] << " " << adot[2] << endl;
    bdot++;
    cout << "b++\n";
    cout << bdot[0] << " " << bdot[1] << " " << bdot[2] << endl;
    adot--;
    cout << "a--\n";
    cout << adot[0] << " " << adot[1] << " " << adot[2] << endl;
    bdot--;
    cout << "b--\n";
    cout << bdot[0] << " " << bdot[1] << " " << bdot[2] << endl;
}
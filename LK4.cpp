#include <iostream>

using namespace std;

class Image
{
    int *img;
    int mx, my;

    public:
        Image(int tmx, int tmy): mx(tmx), my(tmy)
        {
            img = new int[mx*my];
        }

        virtual ~Image()
        {
            delete[] img;
        }

        int get(int x, int y)
        {
            try
            {
                if((y*my+x) > (mx*my) )
                {
                    throw 2;
                }
                return img[y*my+x];
            }
            catch(int error)
            {
                cout << "GetError " << error <<": Out of bounds of array" << endl;
                exit(1);
            }
        }

        int set(int x, int y, int color)
        {
            try
            {
                if((y*my+x) > (mx*my) )
                {
                    throw 3;
                }
                img[y*my+x] = color;
            }
            catch(int error)
            {
                cout << "SetError " << error <<": Out of bounds of array" << endl;
            }
        }
        friend bool operator ==(Image &arrlnt1, Image &arrlnt2)
        {
            if(arrlnt1.mx * arrlnt1.my == arrlnt2.mx * arrlnt2.my)
            {
                for(int i = 0; i < arrlnt1.mx * arrlnt1.my; i++)
                {
                    if(arrlnt1.img[i] == arrlnt2.img[i])
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        int printImg()
        {
            for(int i = 0; i < mx * my; i++)
            {
                cout << img[i] << " ";
            }
            cout << endl;
        }
        
};

int main()
{
    Image img(2, 2);
    img.set(0, 0, 5);
    img.set(1, 0, 5);
    img.set(0, 1, 10);
    img.set(1, 1, 10);
    img.printImg();
    Image img2(2, 2);
    img2.set(0, 0, 5);
    img2.set(1, 0, 5);
    img2.set(0, 1, 10);
    img2.set(1, 1, 10);
    img2.printImg();
    if(img == img2)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}

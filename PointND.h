#ifndef PointND_H
#define PointND_H
#include <vector>
using namespace std;


class PointND {
    public:
        PointND(int n_dimensions);
        PointND(int n_dimensions, float values);
        PointND(vector<float>& valueVec);

        PointND operator+(PointND& p2);

        PointND operator/(float f);

        float getValue(int dimension);

        int getDimensions();

        void print();

        float getDistance(PointND);

    private:
        vector<float> _values;
        int _n_dimensions;
};
#endif

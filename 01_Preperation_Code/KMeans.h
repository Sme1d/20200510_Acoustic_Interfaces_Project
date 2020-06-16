#include <vector>
#include "Point2D.h"
#include "PointND.h"
using namespace std;

class KMeans
{
    public:
        KMeans(int num_of_classes, vector<PointND>& pointVec);
        void inititializeCentroids();
        void updateClassLabels();
        PointND getCentroid(int class_label);
        int getClassLabel(int idx_to_point);
        void updateCentroids();
        void cluster(int n_iterations);
        int classify(PointND point);

    private:
        vector<PointND> _centroids;
        vector<PointND> _points;
        vector<int>     _classLabels;
        vector<int>     _n_class_instances;
        int _n_classes;
        int _n_points;
        int _n_dimensions;
};

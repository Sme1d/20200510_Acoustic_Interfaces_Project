#include "KMeans.h"
#include <iostream>

KMeans::KMeans(int num_of_classes, vector<PointND>& pointVec){
    _points = pointVec;
    _n_classes = num_of_classes;
    _n_points = pointVec.size();
    _n_dimensions = _points[0].getDimensions();

    for(int p=0; p<_n_points; p++){
        _classLabels.push_back(0);
    }
    for(int c=0; c<_n_classes; c++){
        _n_class_instances.push_back(0);
    }

    inititializeCentroids();
}

void KMeans::inititializeCentroids(){
    cout << "Initializing with random centroids" << endl;
    for(int i=0; i<_n_classes; i++){
        PointND centroid = _points[rand() % _n_points];
        //PointND centroid = _points[(2+i*3)-1];
        _centroids.push_back(centroid);
    }
}

void KMeans::updateClassLabels(){
    for(int p=0; p<_n_points; p++){
        _classLabels[p] = classify(_points[p]);
    }
}

void KMeans::cluster(int n_iterations){
    cout << "Clustering over "<<n_iterations<< " iterations"<< endl;
    for(int i=0; i<n_iterations; i++){
        updateClassLabels();
        updateCentroids();
    }
}

int KMeans::classify(PointND point){
    float min_dist = 99999999;
    float associated_class;
    for (int c = 0; c < _n_classes; c++) {
        float dist_to_centroid = point.getDistance(_centroids[c]);
        if (dist_to_centroid < min_dist) {
            min_dist = dist_to_centroid;
            associated_class = c;
        }
    }
    return associated_class;
}

void KMeans::updateCentroids(){
    for(int c=0; c <_n_classes; c++){
        _centroids[c] = PointND(_n_dimensions,0);
        _n_class_instances[c] = 0;

        for(int p=0; p<_n_points; p++){
            if(c == _classLabels[p]){
                _centroids[c] = _centroids[c] + _points[p];
                _n_class_instances[c]++;
            }
        }
        _centroids[c] = _centroids[c] / (float) _n_class_instances[c];
    }
}

PointND KMeans::getCentroid(int class_label){
    return _centroids[class_label];
}

int KMeans::getClassLabel(int idx_to_point){
    return _classLabels[idx_to_point];
}

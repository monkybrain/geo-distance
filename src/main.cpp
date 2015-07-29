#include <iostream>
#include "geo_distance.h"

using namespace std;

int main()
{
    double lat1 = 40.7486;
    double lng1 = -73.9864;
    double lat2 = 41.6548;
    double lng2 = -81.5645;

    double distance1 = haversine_distance(lat1, lng1, lat2, lng2);
    double distance2 = vincenty_distance(lat1, lng1, lat2, lng2);

    cout << "Haversine Distnace: " << distance1 << "km\n";
    cout << "Vincenty Distance:  " << distance2 << "km" << endl;
}


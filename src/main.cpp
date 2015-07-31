#include <iostream>
#include "geo_distance.hpp"

using namespace std;

int main()
{
    double lat1 = 47.6565;
    double lng1 = -122.3191;
    double lat2 = 40.4240;
    double lng2 = 86.9290;

    double distance1 = haversine_distance(lat1, lng1, lat2, lng2);
    double distance2 = vincenty_distance(lat1, lng1, lat2, lng2);

    cout << "Haversine Distnace: " << distance1 << "km\n";
    cout << "Vincenty Distance:  " << distance2 << "km" << endl;
}


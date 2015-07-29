/*
 * Great-circle distance computational forumlas
 *
 * https://en.wikipedia.org/wiki/Great-circle_distance
 */

#include "geo_distance.h"

using namespace std;

double deg_to_rad(double deg)
{
    return (deg * M_PI / 180.0);
}

double haversine_distance(double latitude1, double longitude1, double latitude2,
                          double longitude2)
{
    double lat1 = deg_to_rad(latitude1);
    double lon1 = deg_to_rad(longitude1);
    double lat2 = deg_to_rad(latitude2);
    double lon2 = deg_to_rad(longitude2);

    double d_lat = abs(lat1 - lat2);
    double d_lon = abs(lon1 - lon2);

    double a = pow(sin(d_lat / 2), 2) + cos(lat1) * cos(lat2)
               * pow(sin(d_lon / 2), 2);

    double d_sigma = 2 * asin(sqrt(a));
    //double d_sigma = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earth_radius_km * d_sigma;
}

double vincenty_distance(double latitude1, double longitude1, double latitude2,
                         double longitude2)
{
    double lat1 = deg_to_rad(latitude1);
    double lon1 = deg_to_rad(longitude1);
    double lat2 = deg_to_rad(latitude2);
    double lon2 = deg_to_rad(longitude2);

    double d_lon = abs(lon1 - lon2);

    // Numerator
    double a = pow(cos(lat2) * sin(d_lon), 2);

    double b = cos(lat1) * sin(lat2);
    double c = sin(lat1) * cos(lat2) * cos(d_lon);
    double d = pow(b - c, 2);

    double e = sqrt(a + d);

    // Denominator
    double f = sin(lat1) * sin(lat2);
    double g = cos(lat1) * cos(lat2) * cos(d_lon);

    double h = f + g;

    double d_sigma = atan2(e, h);

    return earth_radius_km * d_sigma;
}


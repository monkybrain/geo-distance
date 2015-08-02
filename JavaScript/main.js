#!/usr/bin/env rhino

load("geo_distance.js")

// White House
var lat1 = 38.8977;
var lng1 = -77.0366;
// Purdue University
var lat2 = 40.4240;
var lng2 = -86.9290;

print("Haversine Distance: ", haversine_distance(lat1, lng1, lat2, lng2));
print("Vincenty Distance:  ", vincenty_distance(lat1, lng1, lat2, lng2));


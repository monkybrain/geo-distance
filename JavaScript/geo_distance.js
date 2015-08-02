var earth_radius_km = 6371.0;
var earth_radius_m  = 6371000.0;
var earth_radius_mi = 3959.0;

function deg_to_rad(deg) {
    return (deg * Math.PI / 180.0);
}

function haversine_distance(latitude1, longitude1, latitude2, longitude2) {
    var lat1 = deg_to_rad(latitude1);
    var lng1 = deg_to_rad(longitude1);
    var lat2 = deg_to_rad(latitude2);
    var lng2 = deg_to_rad(longitude2);

    var d_lat = Math.abs(lat1 - lat2);
    var d_lng = Math.abs(lng1 - lng2);

    var a = Math.pow(Math.sin(d_lat / 2.0), 2.0) + Math.cos(lat1)
            * Math.cos(lat2) * Math.pow(Math.sin(d_lng / 2.0), 2.0);

    var d_sigma = 2.0 * Math.asin(Math.sqrt(a));

    return (earth_radius_km * d_sigma);
}

function vincenty_distance(latitude1, longitude1, latitude2, longitude2) {
    var lat1 = deg_to_rad(latitude1);
    var lng1 = deg_to_rad(longitude1);
    var lat2 = deg_to_rad(latitude2);
    var lng2 = deg_to_rad(longitude2);

    var d_lng = Math.abs(lng1 - lng2);

    // Numerator
    var a = Math.pow(Math.cos(lat2) * Math.sin(d_lng), 2.0);

    var b = Math.cos(lat1) * Math.sin(lat2);
    var c = Math.sin(lat1) * Math.cos(lat2) * Math.cos(d_lng);
    var d = Math.pow(b - c, 2.0);

    var e = Math.sqrt(a + d);

    // Denominator
    var f = Math.sin(lat1) * Math.sin(lat2);
    var g = Math.cos(lat1) * Math.cos(lat2) * Math.cos(d_lng);

    var h = f + g;

    var d_sigma = Math.atan2(e, h);

    return (earth_radius_km * d_sigma);
}


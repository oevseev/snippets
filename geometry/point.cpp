struct Point
{
    int64_t x;
    int64_t y;

    Point() : x(0LL), y(0LL) {}
    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}

    inline Point operator=(Point other) {
        x = other.x;
        y = other.y;
        return other;
    }

    inline Point operator+(Point other) {
        return {x + other.x, y + other.y};
    }

    inline Point operator-(Point other) {
        return {x - other.x, y - other.y};
    }

    inline int64_t operator*(Point other) {
        return x * other.x + y * other.y;
    }

    inline int64_t operator%(Point other) {
        return x * other.y - y * other.x;
    }

    inline bool operator==(Point other) {
        return (x == other.x) && (y == other.y);
    }

    inline bool operator!=(Point other) {
        return !(x == other.x) || !(y == other.y);
    }

    inline bool operator<(Point other) {
        if (x < other.x)
            return true;
        else if (x == other.x)
            return (y < other.y);
        return false;
    }
};

inline int64_t dist_sq(Point a) {
    return a.x * a.x + a.y * a.y;
}

inline double dist(Point a) {
    return sqrt(dist_sq(a));
}

inline double angle(Point a, Point b) {
    return atan2(b.y - a.y, b.x - a.x);
}

inline double vsin(Point a, Point b) {
    return a * b / dist(a) / dist(b);
}

inline double vcos(Point a, Point b) {
    return dot(a, b) / dist(a) / dist(b);
}

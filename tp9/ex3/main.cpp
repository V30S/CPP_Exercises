#include <unordered_map>
#include <functional>

enum class Content
{
    Empty,
    Red,
    Yellow
};

struct Point2d
{
    int x = 0;
    int y = 0;
};

class Point2dHash
{
public:
    std::size_t operator()(const Point2d &point2d) const
    {
        std::size_t hash_x = std::hash<int>{}(point2d.x);
        std::size_t hash_y = std::hash<int>{}(point2d.y);
        return hash_x ^ (hash_y << 1);
    }
};

class Point2dEqual
{
public:
    bool operator()(const Point2d &point2d_f, const Point2d &point2d_s) const
    {
        return point2d_f.x == point2d_s.x && point2d_f.y == point2d_s.y;
    }
};

int main()
{
    std::unordered_map<Point2d, Content, Point2dHash, Point2dEqual> grid;
    grid.emplace(Point2d{3, 4}, Content::Empty);
    grid.emplace(Point2d{-1, 2}, Content::Red);
    return 0;
}
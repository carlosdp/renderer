#include <cmath>

class Vector3 {
  public:
    float x, y, z;

    Vector3() {}

    Vector3(float x, float y, float z)
      : x (x), y (y), z (z) {}

    static const Vector3 &Zero() {
      static const Vector3 result(0.0, 0.0, 0.0);
      return result;
    }

    static const Vector3 &Unit() {
      static const Vector3 result(0.0, 0.0, 0.0);
      return result;
    }

    Vector3 operator+(const Vector3 &other) const {
      return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3& operator+=(const Vector3 &other) {
      x += other.x;
      y += other.y;
      z += other.z;
      return *this;
    }

    Vector3 operator-(const Vector3 &other) const {
      return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3& operator-=(const Vector3 &other) {
      x -= other.x;
      y -= other.y;
      z -= other.z;
      return *this;
    }

    Vector3 operator*(float n) const {
      return Vector3(x * n, y * n, z * n);
    }

    Vector3& operator*=(float n) {
      x *= n;
      y *= n;
      z *= n;
      return *this;
    }

    Vector3 operator/(float n) const {
      n = 1.0 / n;
      return Vector3(x * n, y * n, z * n);
    }

    Vector3& operator/=(float n) {
      n = 1.0 / n;
      x *= n;
      y *= n;
      z *= n;
      return *this;
    }

    Vector3 operator-() const {
      return Vector3(-x, -y, -z);
    }

    /* const float& operator[](size_t i) const { */
    /*   assert(i < 3); */
    /*   return (&x)[i]; */
    /* } */

    /* float& operator[](size_t i) { */
    /*   assert(i < 3); */
    /*   return (&x)[i]; */
    /* } */

    bool operator==(const Vector3 &other) const {
      return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3 &other) const {
      return !operator==(other);
    }
};

inline float dot(const Vector3 &a, const Vector3 &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float squared_length(const Vector3 &v) {
  return v.x*v.x + v.y*v.y + v.z*v.z;
}

inline float length(const Vector3 &v) {
  return sqrt(squared_length(v));
}

inline float distance(const Vector3 &a, const Vector3 &b) {
  return length(a-b);
}

inline float squared_distance(const Vector3 &a, const Vector3 &b) {
  return squared_length(a-b);
}

inline Vector3 normalize(const Vector3 &v) {
  return v / length(v);
}

inline Vector3 vabs(const Vector3 &v) {
  return Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
}

inline Vector3 vmin(const Vector3 &a, const Vector3 &b) {
  return Vector3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}

inline Vector3 vmax(const Vector3 &a, const Vector3 &b) {
  return Vector3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}


#ifndef _2DOBB_H_
#define _2DOBB_H_

#include <limits>
#include <string>
#include <vector>
#include <cmath>

class Vector2
{
public: 
	typedef float data_type;
	
	Vector2() {
		m_Data[0] = m_Data[1] = 0.0f;
	}
 
	Vector2(const Vector2& other) {
		m_Data[0] = other.m_Data[0];
		m_Data[1] = other.m_Data[1];
	}
 
	Vector2(data_type x, data_type y) {
		m_Data[0] = x;
		m_Data[1] = y;
	}
 
	double dot(const Vector2& other) const {
		return other.m_Data[0] * m_Data[0] + other.m_Data[1] * m_Data[1];
	}
 
	double squaredLength() const {
		return sqrtf(m_Data[0]*m_Data[0] + m_Data[1]*m_Data[1]);
	}
 
	Vector2& operator/(data_type factor) {
		m_Data[0] /= factor;
		m_Data[1] /= factor;
		return *this;
	}
 
	Vector2& operator/=(data_type factor) {
		m_Data[0] /= factor;
		m_Data[1] /= factor;
		return *this;
	}
 
	Vector2& operator*(data_type factor) {
		m_Data[0] *= factor;
		m_Data[1] *= factor;
		return *this;
	}
 
	Vector2& operator*=(data_type factor) {
		m_Data[0] *= factor;
		m_Data[1] *= factor;
		return *this;
	}
 
	Vector2& operator+=(const Vector2& other) {
		m_Data[0] += other.m_Data[0];
		m_Data[1] += other.m_Data[1];
		return *this;
	}
 
	Vector2& operator=(const Vector2& other) {
		if (this==&other) {
			return *this;
		}
		m_Data[0] = other.m_Data[0];
		m_Data[1] = other.m_Data[1];
		return *this;
	}
	
	operator const data_type* () const {
		return &(m_Data[0]);
	}
 
	const data_type* data() const {
		return &(m_Data[0]);
	}
 
	friend  Vector2 operator-(const Vector2& first, const Vector2& second) {
		data_type x = first.m_Data[0] - second.m_Data[0];
		data_type y = first.m_Data[1] - second.m_Data[1];
		return Vector2(x, y);
	}
 
	friend Vector2 operator+(const Vector2& first, const Vector2& second) {
		data_type x = first.m_Data[0] + second.m_Data[0];
		data_type y = first.m_Data[1] + second.m_Data[1];
		return Vector2(x, y);
	}
    double x() const { return m_Data[0]; }

     //! Getter for y component
    double y() const { return m_Data[1]; }
private:
	data_type m_Data[2];
 
};
 
class OBB2D {
private:
    /** Corners of the box, where 0 is the lower left. */
    Vector2         corner[4];
 
    /** Two edges of the box extended away from corner[0]. */
    Vector2         axis[2];
 
    /** origin[a] = corner[0].dot(axis[a]); */
    double          minProjLength[2];		// 原点 0点在两个轴上的投影
	double			maxProjLength[2];		// 2点在两个轴上的投影
 
    /** Returns true if other overlaps one dimension of this. */
    bool overlaps1Way(const OBB2D& other) const {
        for (int a = 0; a < 2; ++a) {
 
            double t = other.corner[0].dot(axis[a]);
 
            // Find the extent of box 2 on axis a
            double tMin = t;
            double tMax = t;
 
            for (int c = 1; c < 4; ++c) {
                t = other.corner[c].dot(axis[a]);
 
                if (t < tMin) {
                    tMin = t;
                } else if (t > tMax) {
                    tMax = t;
                }
            }
 
            // We have to subtract off the origin
 
            // See if [tMin, tMax] intersects [minProjLength, maxProjLength]
            if (tMin > maxProjLength[a] || tMax < minProjLength[a]) {
                // There was no intersection along this dimension;
                // the boxes cannot possibly overlap.
                return false;
            }
        }
 
        // There was no dimension along which there is no intersection.
        // Therefore the boxes overlap.
        return true;
    }
 
 
    /** Updates the axes after the corners move.  Assumes the
        corners actually form a rectangle. */
    void computeAxes() {
        axis[0] = corner[1] - corner[0]; 
        axis[1] = corner[3] - corner[0]; 
 
        // Make the length of each axis 1/edge length so we know any
        // dot product must be less than 1 to fall within the edge.
 
        for (int a = 0; a < 2; ++a) {
            axis[a] /= axis[a].squaredLength();
            
			minProjLength[a] = corner[0].dot(axis[a]);
			maxProjLength[a] = corner[2].dot(axis[a]);
        }
    }
 
public:
 
    OBB2D(const Vector2& center, const double w, const double h, double angle)
	{
        Vector2 X( cos(angle), sin(angle));
        Vector2 Y(-sin(angle), cos(angle));
 
        X *= w / 2;
        Y *= h / 2;
 
        corner[0] = center - X - Y;
        corner[1] = center + X - Y;
        corner[2] = center + X + Y;
        corner[3] = center - X + Y;
 
        computeAxes();
    }
 
	void updateAngle(const Vector2& center, const double w, const double h, double angle) {
		Vector2 X( cos(angle), sin(angle));
		Vector2 Y(-sin(angle), cos(angle));
 
		X *= w / 2;
		Y *= h / 2;
 
		corner[0] = center - X - Y;
		corner[1] = center + X - Y;
		corner[2] = center + X + Y;
		corner[3] = center - X + Y;
 
		computeAxes();
	}
 
    /** For testing purposes. */
    void moveTo(const Vector2& center) {
        Vector2 centroid = (corner[0] + corner[1] + corner[2] + corner[3]) / 4;
 
        Vector2 translation = center - centroid;
 
        for (int c = 0; c < 4; ++c) {
            corner[c] += translation;
        }
 
        computeAxes();
    }
 
    /** Returns true if the intersection of the boxes is non-empty. */
    bool overlaps(const OBB2D& other) const {
        return overlaps1Way(other) && other.overlaps1Way(*this);
    }
 
    void render() const {
        glBegin(GL_LINE_LOOP);
            for (int c = 0; c < 5; ++c) {
              glVertex2fv(corner[c & 3]);
            }
        glEnd();
    }
};

class Box2d{
public:
 Box2d() = default;
 Box2d(const Vector2 &center, const double length,
       const double width,const double heading)
     : center_(center),
       length_(length),
       width_(width),
       half_length_(length / 2.0),
       half_width_(width / 2.0),
       heading_(heading),
       cos_heading_(cos(heading)),
       sin_heading_(sin(heading)){
     InitCorners();
 }
 void InitCorners(){
     const double dx1 = cos_heading_ * half_length_;
     const double dy1 = sin_heading_ * half_length_;
     const double dx2 = sin_heading_ * half_width_;
     const double dy2 = -cos_heading_ * half_width_;
     corners_.clear();
     corners_.emplace_back(center_.x() + dx1 + dx2, center_.y() + dy1 + dy2);
     corners_.emplace_back(center_.x() + dx1 - dx2, center_.y() + dy1 - dy2);
     corners_.emplace_back(center_.x() - dx1 - dx2, center_.y() - dy1 - dy2);
     corners_.emplace_back(center_.x() - dx1 + dx2, center_.y() - dy1 + dy2);

     for (auto &corner : corners_) {
       max_x_ = std::fmax(corner.x(), max_x_);
       min_x_ = std::fmin(corner.x(), min_x_);
       max_y_ = std::fmax(corner.y(), max_y_);
       min_y_ = std::fmin(corner.y(), min_y_);
     }
 }
 bool HasOverlap(const Box2d &box) const{
 if (box.max_x() < min_x() || box.min_x() > max_x() || box.max_y() < min_y() ||
     box.min_y() > max_y()) {
   return false;
 }

 const double shift_x = box.center_x() - center_.x();
 const double shift_y = box.center_y() - center_.y();

 const double dx1 = cos_heading_ * half_length_;
 const double dy1 = sin_heading_ * half_length_;
 const double dx2 = sin_heading_ * half_width_;
 const double dy2 = -cos_heading_ * half_width_;
 const double dx3 = box.cos_heading() * box.half_length();
 const double dy3 = box.sin_heading() * box.half_length();
 const double dx4 = box.sin_heading() * box.half_width();
 const double dy4 = -box.cos_heading() * box.half_width();

 return std::abs(shift_x * cos_heading_ + shift_y * sin_heading_) <=
            std::abs(dx3 * cos_heading_ + dy3 * sin_heading_) +
                std::abs(dx4 * cos_heading_ + dy4 * sin_heading_) +
                half_length_ &&
        std::abs(shift_x * sin_heading_ - shift_y * cos_heading_) <=
            std::abs(dx3 * sin_heading_ - dy3 * cos_heading_) +
                std::abs(dx4 * sin_heading_ - dy4 * cos_heading_) +
                half_width_ &&
        std::abs(shift_x * box.cos_heading() + shift_y * box.sin_heading()) <=
            std::abs(dx1 * box.cos_heading() + dy1 * box.sin_heading()) +
                std::abs(dx2 * box.cos_heading() + dy2 * box.sin_heading()) +
                box.half_length() &&
        std::abs(shift_x * box.sin_heading() - shift_y * box.cos_heading()) <=
            std::abs(dx1 * box.sin_heading() - dy1 * box.cos_heading()) +
                std::abs(dx2 * box.sin_heading() - dy2 * box.cos_heading()) +
                box.half_width();
 }


 double max_x() const { return max_x_; }
 double min_x() const { return min_x_; }
 double max_y() const { return max_y_; }
 double min_y() const { return min_y_; }
 const Vector2 &center() const { return center_; }
 double center_x() const { return center_.x(); }
 double center_y() const { return center_.y(); }
 double length() const { return length_; }
 double width() const { return width_; }
 double half_length() const { return half_length_; }
 double half_width() const { return half_width_; }
 double heading() const { return heading_; }
 double cos_heading() const { return cos_heading_; }
 double sin_heading() const { return sin_heading_; }
private:
 Vector2 center_;
 double length_ = 0.0;
 double width_ = 0.0;
 double half_length_ = 0.0;
 double half_width_ = 0.0;
 double heading_ = 0.0;
 double cos_heading_ = 1.0;
 double sin_heading_ = 0.0;

 std::vector<Vector2> corners_;

 double max_x_ = std::numeric_limits<double>::lowest();
 double min_x_ = std::numeric_limits<double>::max();
 double max_y_ = std::numeric_limits<double>::lowest();
 double min_y_ = std::numeric_limits<double>::max();
};

#endif

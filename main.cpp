//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Put the assignment code here

class Quaternion {
  private:
  double a;
  double b;
  double c;
  double d;

  public:
  Quaternion(double c1, double c2, double c3 ,double c4);

  bool operator==(const Quaternion& q);
  Quaternion operator+ (const Quaternion& q);
  Quaternion operator-(const  Quaternion& q);
  Quaternion operator*( double m);

  };

  Quaternion::Quaternion(double c1, double c2, double c3 ,double c4){
    a = c1;
    b = c2;
    c = c3;
    d = c4;
  }

  bool Quaternion::operator==(const Quaternion& q){
    if (( a == q.a) && (b == q.b) && (c == q.c) && (d ==q.d))
    {return true;}
    else { return false;}
  }

  Quaternion Quaternion::operator+ (const Quaternion& q){
    Quaternion p(a,b,c,d);
    p.a = this->a + q.a;
    p.b = this->b + q.b;
    p.c = this->c + q.c;
    p.d = this->d + q.d;
    return p;

  }

  Quaternion Quaternion::operator-(const Quaternion& q){
    Quaternion p(a,b,c,d);
    p.a = this->a - q.a;
    p.b = this->b - q.b;
    p.c = this->c - q.c;
    p.d = this->d - q.d;
    return p;
  }

  Quaternion Quaternion ::operator*( double m){
    Quaternion p(a,b,c,d);
    p.a = this->a * m;
    p.b = this->b * m;
    p.c = this->c * m;
    p.d = this->d * m;
    return p;
  }
  

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------

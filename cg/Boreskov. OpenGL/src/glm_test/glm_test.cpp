#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <glm/vec2.hpp>
#include <glm/matrix.hpp>
#include <glm/mat2x2.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <iostream>

using namespace std;

int main()
{
   glm::vec2 a(1.0f);		      // vector (1, 1)
   glm::vec2 b = a + 1.0f;	      // vector (2, 2)
   glm::vec2 c(2.0f, -1.0f);     // vector (2, -1)
   glm::vec2 d = a + 2.0f*c;     // mul and sum
   glm::vec2 e = -d;

   glm::vec2 f = glm::normalize(e);
   glm::vec2 a2(a.xy);
   glm::vec2 b2(a.xy());

   float dot2 = glm::dot(glm::vec2(1), d); // scalar dot
   float len = glm::length(e);
   float dist = glm::distance(b,c);      // distance between vectors

   bool res = glm::all(glm::equal(a2, b2));

   glm::mat2 m (0, 1, 2, 3);
   glm::mat2 n = glm::matrixCompMult(m, m); // by components mul
   glm::mat2 t = glm::transpose(m);          // AT
   glm::mat2 mi = glm::inverse(m);           // inverse matrix

   glm::vec2 u = mi * c + a;

   glm::vec2 A(1, 2);
   glm::mat2 M(1, 2, 3, 4);

   float* p1 = glm::value_ptr(A);
   float* p2 = glm::value_ptr(M);
   
   return 0;
}


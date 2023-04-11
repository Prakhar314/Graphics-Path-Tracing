#include "../src/ray.hpp"
#include "../src/viewer.hpp"
#include <glm/fwd.hpp>
// example with only diffuse objects
int main() {
  RayTracer raytracer(640, 480, 90, glm::vec3(0), glm::vec3(0, 0, -1),
                      glm::vec3(0, 1, 0), true);
  Viewer viewer(640, 480, "Raytracer");
  vector<Shape *> shapes;
  // make a box using 5 planes
  shapes.push_back(new Plane(glm::vec3(1, 0, 0), -5, glm::vec3(0.2, 0.2, 0.7)));
  shapes.push_back(
      new Plane(glm::vec3(-1, 0, 0), -5, glm::vec3(0.7, 0.2, 0.2)));
  shapes.push_back(new Plane(glm::vec3(0, 1, 0), -5, glm::vec3(0.7, 0.7, 0.2)));
  shapes.push_back(
      new Plane(glm::vec3(0, -1, 0), -5, glm::vec3(0.2, 0.7, 0.2)));
  shapes.push_back(
      new Plane(glm::vec3(0, 0, 1), -13, glm::vec3(0.2, 0.7, 0.7)));

  shapes.push_back(new Sphere(glm::vec3(-0, -2, -6), 2.0f, glm::vec3(1, 0, 0)));
  shapes[shapes.size() - 1]->material = new Transparent(1.5, true);
  shapes.push_back(new Sphere(glm::vec3(-3, -3, -9), 2.0f, glm::vec3(1, 0, 0)));
  shapes[shapes.size() - 1]->material =
      new Metallic(glm::vec3(0.5, 0.5, 0.5), true);
  shapes.push_back(new Cuboid(glm::vec3(1, -4, -12), glm::vec3(4, -1, -9),
                              glm::vec3(0.8, 0.7, 0.5)));

  shapes.push_back(new Cuboid(glm::vec3(-2, 4.9, -11), glm::vec3(2, 5.1, -9),
                              glm::vec3(0), glm::vec3(5)));
  while (!viewer.shouldQuit()) {
    glm::uvec3 **output = raytracer.render(shapes);
    viewer.update(output);
  }
  return 0;
}
#include <igl/readOBJ.h>
#include <igl/writeOBJ.h>
#include <igl/signed_distance.h>
#include <igl/sparse_voxel_grid.h>
#include <igl/copyleft/marching_cubes.h>
#include <igl/fast_winding_number.h>
#include <igl/winding_number.h>
#include <igl/read_triangle_mesh.h>
#include "swept_volume.h"
#include "read_transformation.h"
#include <chrono>

int main(int argc, char *argv[])
{
    std::vector<Eigen::Matrix4d> Transformations;
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::read_triangle_mesh(argv[1],V,F);
    Eigen::MatrixXd U;
    Eigen::MatrixXi G;
    auto starterTime = std::chrono::high_resolution_clock::now();
    swept_volume(V, F, argv[2], 100, "sphereLoopDLoop", U, G);
    auto stopperTime = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(starterTime).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(stopperTime).time_since_epoch().count();
    std::cout << "Silvia's time: " << (end - start) * 0.000001 << std::endl;
    return 0;
}

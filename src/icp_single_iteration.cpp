#include "icp_single_iteration.h"
#include "point_to_plane_rigid_matching.h"
#include "point_to_point_rigid_matching.h"
#include "point_mesh_distance.h"
#include "random_points_on_mesh.h"

void icp_single_iteration(
  const Eigen::MatrixXd & VX,
  const Eigen::MatrixXi & FX,
  const Eigen::MatrixXd & VY,
  const Eigen::MatrixXi & FY,
  const int num_samples,
  const ICPMethod method,
  Eigen::Matrix3d & R,
  Eigen::RowVector3d & t)
{
  // Replace with your code
  // R = Eigen::Matrix3d::Identity();
  // t = Eigen::RowVector3d::Zero();

  Eigen::MatrixXd X;
  random_points_on_mesh(num_samples,VX,FX,X);

  Eigen::MatrixXd P,N;
  Eigen::VectorXd D;
  point_mesh_distance(X,VY,FY,D,P,N);

  if (method == ICP_METHOD_POINT_TO_POINT) {
    point_to_point_rigid_matching(X,P,R,t);
  }
  else { // ICP_METHOD_POINT_TO_PLANE
    point_to_plane_rigid_matching(X,P,N,R,t);
  }
}

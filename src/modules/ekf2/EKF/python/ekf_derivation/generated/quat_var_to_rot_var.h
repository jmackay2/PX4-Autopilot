// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: quat_var_to_rot_var
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     epsilon: Scalar
 *
 * Outputs:
 *     rot_var: Matrix31
 */
template <typename Scalar>
void QuatVarToRotVar(const matrix::Matrix<Scalar, 24, 1>& state,
                     const matrix::Matrix<Scalar, 24, 24>& P, const Scalar epsilon,
                     matrix::Matrix<Scalar, 3, 1>* const rot_var = nullptr) {
  // Total ops: 61

  // Input arrays

  // Intermediate terms (17)
  const Scalar _tmp0 = std::fabs(state(0, 0));
  const Scalar _tmp1 = 1 - epsilon;
  const Scalar _tmp2 = math::min<Scalar>(_tmp0, _tmp1);
  const Scalar _tmp3 = 1 - std::pow(_tmp2, Scalar(2));
  const Scalar _tmp4 = (((state(0, 0)) > 0) - ((state(0, 0)) < 0));
  const Scalar _tmp5 = 2 * math::min<Scalar>(0, _tmp4) + 1;
  const Scalar _tmp6 = _tmp5 * std::acos(_tmp2);
  const Scalar _tmp7 = 2 * _tmp6 / std::sqrt(_tmp3);
  const Scalar _tmp8 = _tmp4 * ((((-_tmp0 + _tmp1) > 0) - ((-_tmp0 + _tmp1) < 0)) + 1);
  const Scalar _tmp9 = _tmp8 * state(1, 0);
  const Scalar _tmp10 = _tmp2 * _tmp6 / (_tmp3 * std::sqrt(_tmp3));
  const Scalar _tmp11 = _tmp5 / _tmp3;
  const Scalar _tmp12 = _tmp10 * _tmp9 - _tmp11 * _tmp9;
  const Scalar _tmp13 = _tmp10 * _tmp8;
  const Scalar _tmp14 = _tmp11 * _tmp8;
  const Scalar _tmp15 = _tmp13 * state(2, 0) - _tmp14 * state(2, 0);
  const Scalar _tmp16 = _tmp13 * state(3, 0) - _tmp14 * state(3, 0);

  // Output terms (1)
  if (rot_var != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _rot_var = (*rot_var);

    _rot_var(0, 0) = _tmp12 * (P(0, 0) * _tmp12 + P(1, 0) * _tmp7) +
                     _tmp7 * (P(0, 1) * _tmp12 + P(1, 1) * _tmp7);
    _rot_var(1, 0) = _tmp15 * (P(0, 0) * _tmp15 + P(2, 0) * _tmp7) +
                     _tmp7 * (P(0, 2) * _tmp15 + P(2, 2) * _tmp7);
    _rot_var(2, 0) = _tmp16 * (P(0, 0) * _tmp16 + P(3, 0) * _tmp7) +
                     _tmp7 * (P(0, 3) * _tmp16 + P(3, 3) * _tmp7);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

int* getCloserDots(int* x_coords, int* y_coords, int dots_num) {
  double min_distance = sqrt(pow(x_coords[1] - x_coords[0], 2) + pow(y_coords[1] - y_coords[0], 2));
  double cur_distance;
  int* result = new int[2];
  result[0] = 0;
  result[1] = 1;
  for (int i = 0; i < dots_num - 1; i++) {
    for (int j = i + 1; j < dots_num; j++) {
      cur_distance = sqrt(pow(x_coords[i] - x_coords[j], 2) + pow(y_coords[i] - y_coords[j], 2));
      if (cur_distance < min_distance) {
        min_distance = cur_distance;
        result[0] = i;
        result[1] = j;
      }
    }
  }
  return result;
}

/**This file implements the hungarian algorithm for allignment problem
From http://soimy.github.io/munkres-opencv/, change int to float
**/
/*
 *   Copyright (c) 2007 John Weaver
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#ifndef HUNGARIAN_HPP
#define HUNGARIAN_HPP

#include "utils.hpp"
#include <list>
#include <utility>
#include <opencv2/opencv.hpp>

class Munkres {
public:
    Munkres();
    ~Munkres() {};
    void solve(cv::Mat_<float> &m);
    void diag(bool);
    get_matched assign(std::vector<data>& dets, std::vector<data>& trks, float iou_threshold = 0.3);
private:
    static const int NORMAL = 0;
    static const int STAR = 1;
    static const int PRIME = 2;
    inline bool find_uncovered_in_matrix(float, unsigned int&, unsigned int&) const;
    inline bool pair_in_list(const std::pair<int, int> &, const std::list<std::pair<int, int> > &);
    int step1(void);
    int step2(void);
    int step3(void);
    int step4(void);
    int step5(void);
    int step6(void);

    cv::Mat_<int> mask_matrix;
    cv::Mat_<float> matrix;
    bool *row_mask;
    bool *col_mask;
    unsigned int saverow, savecol;
    bool isDiag;
};

#endif /* HUNGARIAN_HPP */






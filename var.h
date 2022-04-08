#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#define size 100

using namespace std;


int status;  							// xet dieu kien output
vector<vector<double>> a;  				// vecto luu cac chi so
vector<double> b, c, ct, sga, x;   		// vecto lua cac gia tri xuat phat cua rang buoc, gia tri he so ham muc tieu
										// ..., gia tri delta cua cac cot, ...
vector<int> eql;  						// vecto luu dau cau bai toan
vector<size_t> ar_id, base_id;  		// vecto luu bien phu va bien gia , cac vecto co so cua phuong an
size_t st_num, x_num, x_num_, min_max; 	// so rang buoc, so bien 'x', ..., lua chon output ham muc tieu
size_t add_num=0, ba_num=0, ar_num=0;  	// cac bien them vao bai toan khi dua bai toan ve dang co ban
size_t step = 1, section = 1, count = 1;// 
size_t in, out;							// bien luu hang xoay, cot xoay
double z=0;								// gia tri fx

void inPut();		// ham nhap du lieu
void showOr();		// ham hien thi bai toan ban dau
void showPr();		// ham hien thi bai toan sau khi bien doi (them cac bien phu va bien gia)
void normalize();	// ham chuan hoa bai toan va xay dung bai toan phu
void outPut();		// in ra bang don hinh
void _iterator();	// thuc hien tinh toan bang don hinh
void _result();		// in ra ket qua bai toan
void dataClear();	// xoa du lieu bai toan cu, de nhap du lieu bai toan moi



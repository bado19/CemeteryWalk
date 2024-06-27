#ifndef CSCIx229_H
#define CSCIx229_H

// Include necessary headers
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

// Define any constants

// Function prototypes

void Print(const char* format, ...);
void Project();
void ErrCheck(const char* where);
void Fatal(const char* format, ...);
static void Vertex(double th, double ph);
static void terrain(double x, double y, double z, double dx, double dy, double dz, double th);
static void sphere(double x, double y, double z, double r, int texindx);
static void skullwall1(double x, double y, double z, double dx, double dy, double dz, double th);
static void sphere1(double x, double y, double z, double r);
static void spheredemon(double x, double y, double z, double r, double red, double green, double blue);
static void sphere2(double x, double y, double z, double r1, double r2, double r3);
static void skullwall(double x, double y, double z, double dx, double dy, double dz, double th);
static void crossh(double x, double y, double z, double dx, double dy, double dz, double th, int texindx);
static void cross(double x, double y, double z, double dx, double dy, double dz, double th);
static void wills(double x, double y, double z, double dx, double dy, double dz);
static void cube(double x, double y, double z, double dx, double dy, double dz, double th);

#endif
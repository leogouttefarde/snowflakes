#!/bin/python

import math


def koch(xa, ya, xe, ye):
	xb = xa + (xe-xa)/3
	yb = ya + (ye-ya)/3
	xd = xa + 2 * (xe-xa)/3
	yd = ya + 2 * (ye-ya)/3
	xc = (xb+xd) * math.cos(60*math.pi/180) - (yd-yb) * math.sin(60*math.pi/180)
	yc = (yb+yd) * math.cos(60*math.pi/180) + (xd-xb) * math.sin(60*math.pi/180)
	print xb, yb
	print xc, yc
	print xd, yd

def koch_inv(xa, ya, xe, ye):
	xb = xa + (xe-xa)/3
	yb = ya + (ye-ya)/3
	xd = xa + 2 * (xe-xa)/3
	yd = ya + 2 * (ye-ya)/3
	xc = (xb+xd) * math.cos(60*math.pi/180) + (yd-yb) * math.sin(60*math.pi/180)
	yc = (yb+yd) * math.cos(60*math.pi/180) - (xd-xb) * math.sin(60*math.pi/180)
	print xb, yb
	print xc, yc
	print xd, yd



koch(
	90, 90,
	225, 360
	)


#!/usr/bin/env python

# this is copied from ReactionDecisionMaker/src/ReactiveUtil.py
# used when communicating with the DataServiceProvider
TIMEOUT_ERROR = -10


CLOSE_ENOUGH_TO_GOAL = .5

ANGULAR_ACCEL = 1.0
ANGULAR_INC = .1
ANGULAR_MIN = -.7
ANGULAR_MAX = .7

LINEAR_ACCEL = 1.0
LINEAR_INC = .05
LINEAR_MIN = 0
LINEAR_MAX = .3

CLEARANCE_MIN = .2
CLEARANCE_MAX = 1.5

GOAL_DIST_MAX = 3.0

LINEAR_WEIGHT = .25
CLEARANCE_WEIGHT = .2
GOAL_DIR_WEIGHT = .4
GOAL_DIST_WEIGHT = .1

SLOW_DOWN_RADIUS = 1.0
SIZE_RADIUS = .5
BUFFER_SPACE = 0


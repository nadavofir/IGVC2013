#include "ar_map_navigate_bumpers.h"

int main(int argc, char *argv[])
{
     //setup the ROS node
     ros::init(argc, argv, "ar_map_navigate_bumpers");
     ros::NodeHandle n1, n2, n3, n4;
     vel_pub = n2.advertise<geometry_msgs::Twist>("/cmd_vel", 1); //SET QUEUE SIZE = 1!!! (keep only last msg)
     pospub = n4.advertise<position_tracker::Position>("/position", 1); //SET QUEUE SIZE = 1!!! (keep only last msg)
     pos_sub = n1.subscribe("/position", 1, positionCallback);
     bump_sub = n3.subscribe("/sensorPacket", 1, bumperCallback);

     loadMap();

     loadWaypoints();

     list<position_tracker::Position *>::iterator it;
     for(it = waypoints.begin(); it != waypoints.end(); ++it) //reach every single waypoint generated by the planner
     {
      
        goal_pos_x = (*it)->x;
        goal_pos_y = (*it)->y;

        //move to the next waypoint
        while(sqrt(pow(goal_pos_x - cur_pos.x, 2) + pow(goal_pos_y - cur_pos.y, 2)) > Tdist)
        {
           ros::spinOnce();
        }//end while(current goal is not reached)
     }//end while(1)

}

void loadMap()
{
    //note: ordering of points when adding edges: from left to right, from bottom to top

    //edge AB
	Edge *e1 = new Edge(7.45, 13.67, 14.56, 13.67, 0);
    map4.push_back(e1);

    //edge BC
	Edge *e2 = new Edge(14.56, 13.67, 14.56, 14.38, PI/2);
    map4.push_back(e2);

    //edge DE
	Edge *e3 = new Edge(6.75, 12.55, 14.56, 12.55, 0);
    map4.push_back(e3);

    //edge FE
	Edge *e4 = new Edge(14.56, 6.43, 14.56, 12.55, PI/2);
    map4.push_back(e4);

    //edge HG
	Edge *e5 = new Edge(15.68, 7.54, 15.68, 13.84, PI/2);
    map4.push_back(e5);

    //edge FM
	Edge *e6 = new Edge(14.56, 6.43, 33.26, 6.43, 0);
    map4.push_back(e6);

    //edge HI
	Edge *e7 = new Edge(15.68, 7.54, 25.5, 7.54, 0);
    map4.push_back(e7);

    //edge JK
	Edge *e8 = new Edge(26.5, 7.54, 32.16, 7.54, 0);
    map4.push_back(e8);

    //edge KL
	Edge *e9 = new Edge(32.16, 7.54, 32.16, 17.24, PI/2);
    map4.push_back(e9);

    //edge MN
	Edge *e10 = new Edge(33.26, 6.43, 33.26, 18.04, PI/2);
    map4.push_back(e10);

}

void loadWaypoints()
{
    //HERE: path planning algo will produce path (inputs: map, initial location, end location; outputs: list me waypoints to follow one by one)

   //FOR NOW: I create list me ta waypoints...
   position_tracker::Position *p1 = new  position_tracker::Position();
   p1->x = 15;
   p1->y = 13;  
   waypoints.push_back(p1); 
   position_tracker::Position *p2 = new  position_tracker::Position();
   p2->x = 15;
   p2->y = 7;  
   waypoints.push_back(p2);		
   position_tracker::Position *p3 = new  position_tracker::Position();
   p3->x = 33;
   p3->y = 7;  
   waypoints.push_back(p3);
   position_tracker::Position *p4 = new  position_tracker::Position();
   p4->x = 32.8;
   p4->y = 16;  
   waypoints.push_back(p4);
   waypoints.push_back(p3); 
   waypoints.push_back(p2); 
   waypoints.push_back(p1); 
   position_tracker::Position *p5 = new  position_tracker::Position();
   p5->x = 6;
   p5->y = 13;  
   waypoints.push_back(p5); 
}

void bumperCallback(const irobot_create_2_1::SensorPacketConstPtr& msg)
{
   cur_sensors = *msg;

    //we have recovered from bumping         
    if(!(cur_sensors.bumpLeft || cur_sensors.bumpRight))
    {
        if(!ok_to_drive)
        {
            ros::NodeHandle nn;
            ros::ServiceClient client = nn.serviceClient<position_tracker::SetPosition>("set_position");
            position_tracker::SetPosition srv;            
            srv.request.x = latestBumpPos.x;
            srv.request.y = latestBumpPos.y;
            srv.request.theta = latestBumpPos.theta; //cur_pos.theta + 0.5; //pos.theta + 0.15; //0.15: concludedd from experiments

            if(!client.call(srv))
            {
                ROS_ERROR("Failed to call service setPosition");
            }

            ok_to_drive = 1;
            prevBump = 0;
        }
        
        return;
    }


    ok_to_drive = 0;
   geometry_msgs::Twist twist;
   twist.angular.z = 0.0;
   twist.linear.x = 0.0;

   //we've hit something hard or head-on.  Back away slowly.
   if(cur_sensors.bumpLeft && cur_sensors.bumpRight)
   {
      twist.linear.x = -0.1; //-0.1;
      prevBump = 1;
   }
   else if(cur_sensors.bumpLeft)
   {   
      twist.angular.z = -0.1; //-0.1;
      if(!prevBump)
      {
            latestBumpPos = getClosestLeftLineProjection();
            //pospub.publish(pos);
            cout << "BUMPED LEFT:" << endl;
            cout << "latestBumpPos.x = " << latestBumpPos.x << endl;
            cout << "latestBumpPos.y = " << latestBumpPos.y << endl;
            cout << "latestBumpPos.theta = " << latestBumpPos.theta << endl;
      }
      prevBump = 1;
   }
   else if(cur_sensors.bumpRight)
   {
      twist.angular.z = 0.1;
      if(!prevBump)
      {
            latestBumpPos = getClosestRightLineProjection();
            //pospub.publish(pos);
            cout << "BUMPED RIGHT:" << endl;
            cout << "latestBumpPos.x = " << latestBumpPos.x << endl;
            cout << "latestBumpPos.y = " << latestBumpPos.y << endl;
            cout << "latestBumpPos.theta = " << latestBumpPos.theta << endl;

      }
      prevBump = 1;
   }

   vel_pub.publish(twist);
}

//in positionhandler function
void positionCallback(const position_tracker::PositionConstPtr& msg)
{
   if(!ok_to_drive)
      return;

   cur_pos = *msg;

   cout << "CUR_POS.x = " << cur_pos.x << endl;
   cout << "CUR_POS.y = " << cur_pos.y << endl;
   cout << "CUR_POS.theta = " << cur_pos.theta << endl;
   cout << "goal_pos_x = " << goal_pos_x << endl;
   cout << "goal_pos_y = " << goal_pos_y << endl;

   double x_delta = goal_pos_x - cur_pos.x;
   double y_delta = goal_pos_y - cur_pos.y; 
   
   //double m = (cur_pos_y - goal_pos_y)/(cur_pos_x - goal_pos_x);
   double goal_theta = atan2(y_delta, x_delta); // use math.h for atan (then make sure it's in [-pi, pi] range

   double theta_delta = goal_theta - cur_pos.theta;
   if(theta_delta > PI)
   {
       theta_delta = -2*PI + theta_delta;
   }
   else if(theta_delta < -PI)
   {
       theta_delta = 2*PI + theta_delta;
   }

   double goal_distance = sqrt(pow(x_delta, 2) + pow(y_delta, 2));
   
   geometry_msgs::Twist twist;
   twist.angular.z = 0.0;
   twist.linear.x = 0.0;

   if(fabs(theta_delta) > 0.5)
      twist.angular.z = copysign(0.5, theta_delta);
   else
      twist.angular.z = theta_delta;

   if(fabs(theta_delta) > 0.1)
   {
      twist.linear.x = 0.0;
   }
   else if(goal_distance > 0.25)
   {
      twist.linear.x = 0.25;  //0.05 for DEBUGGING!!!, 0.5 for max sustainable speed
   }
   else if(goal_distance > 0.1)
   {
      twist.linear.x = goal_distance; //0.05 for DEBUGGING!!!
   }
   else
   {
      twist.linear.x = 0.0;
      twist.angular.z = 0.0;
   }
 
   vel_pub.publish(twist);
}

position_tracker::Position getClosestLeftLineProjection()
{

   //WHAT IF THERE IS NO LINE TO THE LEFT OF THE ROBOT???

   double min_dist = 100000000;
   position_tracker::Position *tmp_pos = new position_tracker::Position();
   tmp_pos->x = -1;
   tmp_pos->y = -1;
   tmp_pos->theta = -1;

   list<Edge *>::iterator i;   
   for(i = map4.begin(); i != map4.end(); ++i) //for each edge in the map
   {
      Edge *e = *i;
      double D[2][2] = {{(e->Bx - e->Ax), (e->By - e->Ay)}, {(cur_pos.x - e->Ax), (cur_pos.y - e->Ay)}};

      /*cout << "D[0][0] = " << D[0][0] << endl;
      cout << "D[0][1] = " << D[0][1] << endl;
      cout << "D[1][0] = " << D[1][0] << endl;
      cout << "D[1][1] = " << D[1][1] << endl;*/

      cout << "cur_pos.x = " << cur_pos.x << endl;
      cout << "cur_pos.y = " << cur_pos.y << endl;
      cout << "cur_pos.theta = " << cur_pos.theta << endl;
      cout << "e->Ax = " << e->Ax << endl;
      cout << "e->Ay = " << e->Ay << endl;
      cout << "e->Bx = " << e->Bx << endl;
      cout << "e->By = " << e->By << endl;
      cout << "e->theta = " << e->theta << endl;
      cout << "det(D) = " << det(D) << endl;


      //keep only the lines to the left of the current robot pos
      if((det(D) < 0 && fabs(det(D)) > 0.0001 && (cur_pos.theta > e->theta - PI/2 && cur_pos.theta < e->theta + PI/2)) || (det(D) > 0  && fabs(det(D)) > 0.0001 && (cur_pos.theta < e->theta - PI/2 || cur_pos.theta > e->theta + PI/2)))
      {
          //find the projection of the current point to the last identified left line
          double A[2][2] = {{(e->Bx - e->Ax), (e->By - e->Ay)}, {(e->Ay - e->By), (e->Bx - e->Ax)}};
          double X[2] = {0, 0};
          double B[2] = {cur_pos.x*(e->Bx - e->Ax) + cur_pos.y*(e->By - e->Ay), e->Ay*(e->Bx - e->Ax) - e->Ax*(e->By - e->Ay)};
          solve(A, B, X);

            
          //discard line segment if the projection falls outside its boundaries
          if(e->theta < 0.1 ) //horizontal line
          {
              if(X[0] > e->Bx || X[0] < e->Ax)
                 continue;
          }
		  else{ //vertical line
              if(X[1] > e->By || X[1] < e->Ay)
                 continue; 

          }
          

      cout << "line to the LEFT of the robot" << endl;
/*      cout << "cur_pos.x = " << cur_pos.x << endl;
      cout << "cur_pos.y = " << cur_pos.y << endl;
      cout << "cur_pos.theta = " << cur_pos.theta << endl;
      cout << "e->Ax = " << e->Ax << endl;
      cout << "e->Ay = " << e->Ay << endl;
      cout << "e->Bx = " << e->Bx << endl;
      cout << "e->By = " << e->By << endl;
      cout << "e->theta = " << e->theta << endl;*/

          //calculate the distance between the projection and the current robot location
          double sdist = sqrt(pow(cur_pos.x - X[0], 2) + pow(cur_pos.y - X[1], 2));

          //keep the projection with the min distance from the current pos
          if(sdist < min_dist)
          {
              min_dist = sdist;
              tmp_pos->x = X[0] + (0.05/sdist)*(cur_pos.x - X[0]); //X[0]; //15 cm away from the wall may seem hard, but it handles the doors in the building
              tmp_pos->y = X[1] + (0.05/sdist)*(cur_pos.y - X[1]); //X[1];


			  double angle1 = e->theta;
			  double angle2 = e->theta + PI;
              if(angle1 > PI)
                   angle1 = -2*PI + angle1;
              else if(angle1 < -PI)
                   angle1 = 2*PI + angle1;

              if(angle2 > PI)
                   angle2 = -2*PI + angle2;
              else if(angle2 < -PI)
                   angle2 = 2*PI + angle2;

              double diff1 = angle1 - cur_pos.theta;
              double diff2 = angle2 - cur_pos.theta;

              if(fabs(diff1) < fabs(diff2))
                   tmp_pos->theta = angle1; 
              else
                   tmp_pos->theta = angle2; 

      cout << "angle1 = " << angle1 << endl;
      cout << "angle2 = " << angle2 << endl;
      cout << "tmp_pos->theta = " << tmp_pos->theta << endl;


      cout << "cur_pos.x = " << cur_pos.x << endl;
      cout << "cur_pos.y = " << cur_pos.y << endl;
      cout << "cur_pos.theta = " << cur_pos.theta << endl;
      cout << "e->Ax = " << e->Ax << endl;
      cout << "e->Ay = " << e->Ay << endl;
      cout << "e->Bx = " << e->Bx << endl;
      cout << "e->By = " << e->By << endl;
      cout << "e->theta = " << e->theta << endl;
      cout << "det(D) = " << det(D) << endl;

          }
      }
   }
  
   return *tmp_pos;

}

position_tracker::Position getClosestRightLineProjection()
{

   //WHAT IF THERE IS NO LINE TO THE RIGHT OF THE ROBOT???

   double min_dist = 100000000;
   position_tracker::Position *tmp_pos = new position_tracker::Position();
   tmp_pos->x = -1;
   tmp_pos->y = -1;
   tmp_pos->theta = -1;

   list<Edge *>::iterator i;   
   for(i = map4.begin(); i != map4.end(); ++i) //for each edge in the map
   {
      Edge *e = *i;
      double D[2][2] = {{(e->Bx - e->Ax), (e->By - e->Ay)}, {(cur_pos.x - e->Ax), (cur_pos.y - e->Ay)}};

/*      cout << "cur_pos.x = " << cur_pos.x << endl;
      cout << "cur_pos.y = " << cur_pos.y << endl;
      cout << "cur_pos.theta = " << cur_pos.theta << endl;
      cout << "e->Ax = " << e->Ax << endl;
      cout << "e->Ay = " << e->Ay << endl;
      cout << "e->Bx = " << e->Bx << endl;
      cout << "e->By = " << e->By << endl;
      cout << "e->theta = " << e->theta << endl;
      cout << "det(D) = " << det(D) << endl;*/

      //keep only the lines to the right of the current robot pos
      if((det(D) > 0  && fabs(det(D)) > 0.0001 && (cur_pos.theta > e->theta - PI/2 && cur_pos.theta < e->theta + PI/2)) || (det(D) < 0  && fabs(det(D)) > 0.0001 && (cur_pos.theta < e->theta - PI/2 || cur_pos.theta > e->theta + PI/2)))
      {
          //find the projection of the current point to the last identified left line
          double A[2][2] = {{(e->Bx - e->Ax), (e->By - e->Ay)}, {(e->Ay - e->By), (e->Bx - e->Ax)}};
          double X[2] = {0, 0};
          double B[2] = {cur_pos.x*(e->Bx - e->Ax) + cur_pos.y*(e->By - e->Ay), e->Ay*(e->Bx - e->Ax) - e->Ax*(e->By - e->Ay)};
          solve(A, B, X);

          //discard line segment if the projection falls outside its boundaries
          if(e->theta < 0.1 ) //horizontal line
          {
              if(X[0] > e->Bx || X[0] < e->Ax)
                 continue;
          }
		  else{ //vertical line
              if(X[1] > e->By || X[1] < e->Ay)
                 continue; 
          }

          cout << "line to the RIGHT of the robot" << endl;

          //calculate the distance between the projection and the current robot location
          double sdist = pow(cur_pos.x - X[0], 2) + pow(cur_pos.y - X[1], 2);

          //keep the projection with the min distance from the current pos
          if(sdist < min_dist)
          {
              min_dist = sdist;
              tmp_pos->x = X[0] + (0.05/sdist)*(cur_pos.x - X[0]); //X[0];
              tmp_pos->y = X[1] + (0.05/sdist)*(cur_pos.y - X[1]); //X[1];


			  double angle1 = e->theta;
			  double angle2 = e->theta + PI;
              if(angle1 > PI)
                   angle1 = -2*PI + angle1;
              else if(angle1 < -PI)
                   angle1 = 2*PI + angle1;

              if(angle2 > PI)
                   angle2 = -2*PI + angle2;
              else if(angle2 < -PI)
                   angle2 = 2*PI + angle2;

              double diff1 = angle1 - cur_pos.theta;
              double diff2 = angle2 - cur_pos.theta;

              if(fabs(diff1) < fabs(diff2))
                   tmp_pos->theta = angle1; 
              else
                   tmp_pos->theta = angle2; 

      cout << "angle1 = " << angle1 << endl;
      cout << "angle2 = " << angle2 << endl;
      cout << "tmp_pos->theta = " << tmp_pos->theta << endl;

      cout << "cur_pos.x = " << cur_pos.x << endl;
      cout << "cur_pos.y = " << cur_pos.y << endl;
      cout << "cur_pos.theta = " << cur_pos.theta << endl;
      cout << "e->Ax = " << e->Ax << endl;
      cout << "e->Ay = " << e->Ay << endl;
      cout << "e->Bx = " << e->Bx << endl;
      cout << "e->By = " << e->By << endl;
      cout << "e->theta = " << e->theta << endl;
      cout << "det(D) = " << det(D) << endl;

          }
      }
   }

   return *tmp_pos;

}

// det = ad - bc
double det(double A[2][2])
{
   return(A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

// D = 1/det(A)
//
// .............. | d -b | . | D*d -D*b |
// inv = D * |-c a | = |-D*c D*a |
void inv(double A[2][2], double IA[2][2])
{
   double D = 1/det(A);
   IA[0][0] = +D*A[1][1];
   IA[0][1] = -D*A[0][1];
   IA[1][0] = -D*A[1][0];
   IA[1][1] = +D*A[0][0];
}

// |a b| |x| . |e|
// |c d| |y| = |f|
//
// |x| . |a b|-1 |e|
// |y| = |c d| .. |f|
void solve(double A[2][2], double C[2], double S[2])
{
 double IA[2][2];
 inv(A, IA);
 S[0] = IA[0][0]*C[0] + IA[0][1]*C[1];
 S[1] = IA[1][0]*C[0] + IA[1][1]*C[1];
}

void substring(const char* text, int start, int stop, char *new_string)
{
    sprintf(new_string, "%.*s", stop - start, &text[start]);
}

string char_to_string(char *input_p)
{
    string str(input_p);
    return str;
}

void error(char *msg)
{
    perror(msg);
    exit(1);
}



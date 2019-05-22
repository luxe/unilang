

void setup() {
  size(1024, 640);
}

void add_lane(event_annotated_route r, String submap, float distance){
  lane_event event = new lane_event();
  event.entrance_event = event_action.event_action_regenerate;
  event.lane.map_ref.map_index = submap;
  event.lane.annotation.distance = distance;
  r.event_lane_sequence.add(event);
}
void draw() {

  
  event_annotated_route r = new event_annotated_route();
  add_lane(r,"A",50);
  add_lane(r,"A",50);
  add_lane(r,"B",50);
  add_lane(r,"B",50);
  add_lane(r,"A",50);
  add_lane(r,"A",50);
  
  int x_screen_offsett = 5;
  int y_screen_offsett = 30;
  background(#FFFFFF);
  display(r,x_screen_offsett,y_screen_offsett);

}
void display(event_annotated_route r, int x, int y){
  
  display(r.route_plan_id,x,y);
  display(r.event_lane_sequence,x,y);
  display(r.evaluation_range,x,y);
  
  //sizes
  int rec_width = 40;
  int rec_height = 40;
  
  //colors
  color white = #FFFFFF;
  color gray = #C3C8C9;
  color blue = #8DD4E5;
  color light_green = #ADC48E;
  
  for (int i=0; i < r.event_lane_sequence.size(); ++i){
    draw_lane(x+(rec_width*i), y, rec_width, rec_height,gray,light_green,str(r.event_lane_sequence.get(i).lane.annotation.distance));
  }
}

void display(route_plan_identifier route_plan_id, int x, int y){
}
void display(ArrayList<lane_event> event_lane_sequence, int x, int y){
  for (int i=0; i < event_lane_sequence.size(); ++i){
    display(event_lane_sequence.get(i),i,x,y);
  }
}
void display(event_view evaluation_range, int x, int y){
}
void display(lane_event event, int index, int x, int y){
}



void draw_lane(int x, int y, int width, int height, color lane_color, color submap_color, String label){
  draw_submap(x,y-20,width,height+40,submap_color,label);
  fill(lane_color);
  rect(x,y,width,height);
  fill(#FFFFFF);
  draw_label(label,x+5,y+height-5,12,#000000,"Cantarell-Regular-48.vlw");
}

void draw_submap(int x, int y, int width, int height, color c, String label){
  stroke(c);
  fill(c);
  rect(x,y,width,height);
  fill(#FFFFFF);
  stroke(#000000);
}

void draw_label(String str, int x, int y, int size, color c, String font){
   fill(c);
   //PFont f = loadFont(font);
   //textFont(f);
   textSize(size);
   text(str, x, y);
   fill(#000000);
}

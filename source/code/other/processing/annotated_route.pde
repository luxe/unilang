///
///   Uber, Inc. (c) 2018.
///   
///   @brief Local Map Regeneration Trigger Framework data and configuration.
///   @details Contains data types created by and used within the framework.
///   
///   @addtogroup Regeneration
///   @{
///

//Mocks brought over manually
class map_ref_id{
    String element_id = new String();
    String map_index = new String();
    String entry_point_id = new String();
}

class lane_neighbor_annotation{
  float distance;
}

class route_plan_identifier
{
    String route_identifier = new String();
    String target_identifier = new String();
    String chunk_identifier = new String();
}


///
///   @brief   The various event states that can occur on lanes.
///   @details The regeneration framework will tag events to particular lane.
///
enum event_action {

    // Causes the regenerate trigger to be called on the corresponding
    // lane.
    event_action_regenerate,

    // Causes nothing to trigger for the corresponding lane.
    event_action_none,
} 

///
///   @brief   The reason we are regenerating on a particular lane.
///   @details Primarily used to aid in debugging.
///
enum regeneration_reason {

    // Regenerating because of distance.
    regeneration_reason_distance,

    // Regenerating because of submap loops.
    regeneration_reason_submap_loop,

    // No reason to regenerate.
    regeneration_reason_none,
} 

///
///   @brief   An interpretation on how to process the route based on the state
///            of the event view.
///   @details We keep an interval over the route in order to determine what
///            events need to be processed. However, a new route can't have a
///            starting position in the interval (because no previous lane was
///            visited). And an expired route has no ending position in the
///            interval (because the progress index may no longer correlate to
///            the route). We observe the optionality of the event view to
///            determine the contextual state of the route.
///
enum route_status {

    // No previous lane was visited. we can assume all lanes up to the
    // current.
    route_status_new_route,

    // We have a previous and current lane giving us a valid interval
    // over the route.
    route_status_existing_route,

    // No current lane is given. we an assume all lanes from the
    // previous to the end of the route.
    route_status_expired,

    // We do not have a valid interval over the route at all.
    route_status_invalid,
} 

///
/// @struct  lane_info
/// @brief   Lane information within a particular route.
/// @details Lane information for a single element from a translated route.
///
class lane_info
{
    ///
    /// @var     map_ref
    /// @brief   The identity of the lane.
    /// @details Derived from the lane sequence of the translated route.
    ///
    map_ref_id map_ref = new map_ref_id();

    ///
    /// @var     annotation
    /// @brief   Lane information within a particular route.
    /// @details Lane information for a single element from a translated route.
    ///
    lane_neighbor_annotation annotation = new lane_neighbor_annotation();
}

///
/// @struct  lane_event
/// @brief   A lane with annotated event information.
/// @details Contains event information about the particular lane.
///
class lane_event
{

    ///
    /// @var     lane
    /// @brief   The lane that the event may occur on.
    /// @details Derived from the annotation and lane sequence of the translated
    ///          route.
    ///
    lane_info lane = new lane_info();

    ///
    /// @var     entrance_event
    /// @brief   A regeneration event that will trigger when the lane is reached.
    /// @details A user callback will be made for the event of the given lane.
    ///
    event_action entrance_event;

    ///
    /// @var     reason
    /// @brief   Why we may be regenerating on a lane.
    /// @details Provides explanation on why a regeneration event is present.
    ///
    regeneration_reason reason;
}

///
/// @struct  event_view
/// @brief   The previously determined lane, and the new currently determined
///          lane.
/// @details Creates an interval of lanes to evaluate for events. This is a
///          partially open interval (prev,curr]. Why are they optionals? A
///          new route has no previous index. If the car drives past the end
///          of the route, there is no current index.
///
class event_view
{

    ///
    /// @var     previous
    /// @brief   The previous lane observed.
    /// @details Interval end is open.
    ///
    int previous;

    ///
    /// @var     current
    /// @brief   The current lane observed.
    /// @details Interval end is closed.
    ///
    int current;
}

///
/// @struct  event_annotated_route
/// @brief   The sequence of regeneration events that occur along a route.
/// @details The events will be triggered in the order of the sequence.
///
class event_annotated_route
{

    ///
    /// @var     route_plan_id
    /// @brief   The unique id of the route plan.
    /// @details Sourced from navigator.
    ///
    route_plan_identifier route_plan_id = new route_plan_identifier();

    ///
    /// @var     event_lane_sequence
    /// @brief   The regeneration events that should occur on the change of
    ///          particular lanes.
    /// @details The change in lanes is expected to be in the same order that
    ///          they appear in the original route. The sequence may contain
    ///          duplicate lanes. We are simply taking an existing route, and
    ///          tagging it with events.
    ///
    ArrayList<lane_event> event_lane_sequence = new ArrayList<lane_event>();

    ///
    /// @var     evaluation_range
    /// @brief   The interval of lanes that need to be evaluated for events.
    /// @details Uses the previous and current lanes observed to create an
    ///          interval for evaluation. The reason we do this, is because we may
    ///          not evaluate every lane as we pass over them. We need to make
    ///          sure we don't forget to evaluate lanes that we have already
    ///          passed over.
    ///
    event_view evaluation_range = new event_view();
}

///@}

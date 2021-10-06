#pragma once

//the base level sorting algorithm employed when printing functions
enum class Method_Sort_Algorithm
{KEEP_WRITTEN_ORDER         //name
,ALPHABETICALLY_BY_NAME     //name
,ALPHABETICALLY_BY_SUBGROUP //subgroup
,BY_CUSTOM_SUBGROUP_LIST    //subgroup
};

//only occurs when BY_CUSTOM_SUBGROUP_LIST is chosen
enum class Method_Sort_For_Left_Over_Subgroups_When_Using_Subgroup_Algorithm
{KEEP_WRITTEN_ORDER
,ALPHABETICALLY_BY_SUBGROUP
};

//only occurs when ALPHABETICALLY_BY_SUBGROUP or BY_CUSTOM_SUBGROUP_LIST is chosen
enum class Method_Sort_Within_Subgroup_Algorithm
{KEEP_WRITTEN_ORDER
,ALPHABETICALLY_BY_NAME
};

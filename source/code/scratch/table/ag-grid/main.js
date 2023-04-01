function rowSpan(params) {
  var behaviourGroup = params.data ? params.data.behaviour_group : undefined;
  if (behaviourGroup === 'Autonomy Envelope') {
    return 3;
  }
    return 1;
  }

const columnDefs = [
  { field: 'behaviour_group', headerName: 'Behaviour Group', rowSpan: rowSpan,
    cellClassRules: {'show-cell': 'value !== undefined',},
  },
  { field: 'behaviour', headerName: 'Behaviour'},
  { field: 'verification_method', headerName: 'Verification Method'},
  { field: 'owner', headerName: 'Owner'},
  {
    headerName: 'Requirements',
    children: [
      { field: 'requirement_status', headerName: 'Status'},
      { field: 'requirement_date', headerName: 'Due Date'},
    ],
  },
  {
    headerName: 'Verification Plan',
    children: [
      { field: 'verification_status', headerName: 'Status'},
      { field: 'verification_date', headerName: 'Due Date'},
    ],
  },
  {
    headerName: 'Test Case Ready',
    children: [
      { field: 'test_case_status', headerName: 'Status'},
      { field: 'test_case_date', headerName: 'Due Date'},
    ],
  },
  {
    headerName: 'Data Ready',
    children: [
      { field: 'data_status', headerName: 'Status'},
      { field: 'data_date', headerName: 'Due Date'},
    ],
  },
  {
    headerName: 'Implementation Complete',
    children: [
      { field: 'impl_status', headerName: 'Status'},
      { field: 'impl_date', headerName: 'Due Date'},
    ],
  },
  {
    headerName: 'Test Execution',
    children: [
      { field: 'test_execution_status', headerName: 'Status'},
      { field: 'test_execution_date', headerName: 'Due Date'},
    ],
  },
  { field: 'mission_ready', headerName: 'Mission Ready'},
];

// specify the data
const rowData = [
  {
    behaviour_group: "Autonomy Envelope",
    behaviour: "Vehicle Behaviors",
    verification_method: "DVP",
    owner: "NA",
    requirement_status: "X", requirement_date: "Y",
    verification_status: "X2", verification_date: "Y2",
    test_case_status: "X3", test_case_date: "Y3",
    data_status: "X4", data_date: "Y4",
    impl_status: "X5", impl_date: "Y5",
    test_execution_status: "X6", test_execution_date: "Y6",
  },
  {
    //behaviour_group: "Autonomy Envelope",
    behaviour: "Bounding Objects / Scenarios (Perception)",
    verification_method: "DVP",
    owner: "NA",
    requirement_status: "X", requirement_date: "Y",
    verification_status: "X2", verification_date: "Y2",
    test_case_status: "X3", test_case_date: "Y3",
    data_status: "X4", data_date: "Y4",
    impl_status: "X5", impl_date: "Y5",
    test_execution_status: "X6", test_execution_date: "Y6",
  },
  {
    //behaviour_group: "Autonomy Envelope",
    behaviour: "Bounding Objects/Scenarios (Other)",
    verification_method: "DVP",
    owner: "NA",
    requirement_status: "X", requirement_date: "Y",
    verification_status: "X2", verification_date: "Y2",
    test_case_status: "X3", test_case_date: "Y3",
    data_status: "X4", data_date: "Y4",
    impl_status: "X5", impl_date: "Y5",
    test_execution_status: "X6", test_execution_date: "Y6",
  },
];

// let the grid know which columns and what data to use
const gridOptions = {
  columnDefs: columnDefs,
  suppressRowTransform: true,
  rowData: rowData,
  defaultColDef: {
    editable: true,
    sortable: true,
    filter: true,
    resizable: true,
  },
  //sideBar: 'columns',
};

// setup the grid after the page has finished loading
document.addEventListener('DOMContentLoaded', () => {
    const gridDiv = document.querySelector('#myGrid');
    new agGrid.Grid(gridDiv, gridOptions);
});
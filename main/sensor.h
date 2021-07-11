void readSensor(int * cds, int * temp); //센서값을 받아와서 저장해요.

bool Check_condition(int temp, int temp_th, bool tempMorethan, int cds, int cds_th, bool cdsMorethan, bool And);
//문을 여는지 닫는지 판단하는 함수 true 열어, false 닫아

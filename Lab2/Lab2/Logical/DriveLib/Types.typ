
TYPE
	DoorStates : 
		(
		ST_INIT := 0,
		ST_UNKNOWN := 1,
		ST_OPEN := 2,
		ST_CLOSE := 3,
		ST_ACC_POS := 4,
		ST_ACC_NEG := 5,
		ST_POS := 6,
		ST_NEG := 7,
		ST_DEC_POS := 8,
		ST_DEC_NEG := 9
		);
	DriveStates : 
		(
		ST_SWITCHED_ON := 35,
		ST_READY := 33,
		ST_DISABLED := 64
		);
	DriveCommands : 
		(
		CMD_SWITCH_ON := 7,
		CMD_ENABLE := 15,
		CMD_SHUTDOWN := 6
		);
END_TYPE

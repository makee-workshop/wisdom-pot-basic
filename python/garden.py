import time
import sys
import websocket
import datetime
sys.path.insert(0, '/usr/lib/python2.7/bridge/')
from bridgeclient import BridgeClient as bridgeclient

value = bridgeclient()

websocket.enableTrace(True)
ws = websocket.create_connection($WEBSOCKET_URL)


while True:
	h0 = value.get("H0")
	t0 = value.get("T0")
	l0 = value.get("L0")
	d0 = value.get("D0")

	t = time.time();
	date = datetime.datetime.fromtimestamp(t).strftime('%Y%m%d%H%M%S')

	vals = "{\"date\":\""+date+"\",\"h\":"+h0+",\"t\":"+t0+",\"l\":"+l0+",\"d\":"+d0+"}"

	time.sleep(1);
	ws.send(vals);
	print vals;

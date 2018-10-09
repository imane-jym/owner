#!/bin/bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
protoc ./PacketDef.proto --cpp_out=.
#protoc ./protocol_c2s.proto --cpp_out=.
#protoc ./protocol_s2c.proto --cpp_out=.
#protoc ./protocol_lobby_dir.proto --cpp_out=.
#protoc ./protocol_local.proto --cpp_out=.
#protoc ./protocol_server_log.proto --cpp_out=.
#protoc ./protocol_netprocess.proto --cpp_out=.
protoc ./protocol_lobby_client.proto --cpp_out=.

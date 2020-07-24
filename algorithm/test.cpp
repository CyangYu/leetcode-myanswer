#include <stdio.h>
#include <stdlib.h> 
#include <inttypes.h>

typedef struct {
	uint8_t *bytes;
	int offset;
	int legnth;
} stream_t;

typedef union {
	uint8_t bytes[4];
	int32_t int32;
	uint32_t uint32;
} union_int;

inline void read_uint32(stream_t *stream, union_int *ui) {
	ui->bytes[0] = stream->bytes[stream->offset + 0];
	ui->bytes[1] = stream->bytes[stream->offset + 1];
	ui->bytes[2] = stream->bytes[stream->offset + 2];
	ui->bytes[3] = stream->bytes[stream->offset + 3];
	stream->offset += 4;
}

int extract_cmpt(stream_t *stream, const char *filename) {
	if (stream == NULL || stream->bytes == NULL) {
		return -1;	
	}

	union_int ui;
	union_int *pui = &ui;

	read_uint32(stream, pui);
	uint32_t magic = ui.uint32;

	read_uint32(stream, pui);
	uint32_t version = ui.uint32;

	read_uint32(stream, pui);
	uint32_t total_len = ui.uint32;

	FILE *fp = fopen(filename, "wb+");
	if (fp == NULL) {
		return -1;
	}

	stream->offset -= 12;
	fwrite((stream->bytes + stream->offset), sizeof(uint8_t), total_len, fp);
	fclose(fp);

	stream->offset += total_len;
	return 0;
}

int main(int argc, char *argv[]) {
	const char *input = argv[1];

	FILE *fp = fopen(input, "rb");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}

	fseek(fp, 0, SEEK_END);
	long cmpt_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	stream_t stream;
	stream_t *pstream = &stream;

	union_int ui;
	union_int *pui = &ui;

	stream.bytes = (uint8_t *)malloc(sizeof(uint8_t) * cmpt_size);
	stream.offset = 0;
	stream.legnth = cmpt_size;

	fread(stream.bytes, sizeof(uint8_t), stream.legnth, fp);
	
	read_uint32(pstream, pui);
	uint32_t magic = ui.uint32;

	read_uint32(pstream, pui);
	uint32_t version = ui.uint32;

	read_uint32(pstream, pui);
	uint32_t total_len = ui.uint32;

	read_uint32(pstream, pui);
	uint32_t tiles_count = ui.uint32;

	char *filename = (char *)malloc(sizeof(char) * 8);
	
	for (int i = 0; i < tiles_count; i++) {
		sprintf(filename, "%d.b3dm", i);
		extract_cmpt(pstream, filename);
	}

	free(filename);
	free(stream.bytes);
	return EXIT_SUCCESS;
}
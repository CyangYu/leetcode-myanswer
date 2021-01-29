#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char *argv[])
{
	if (argc < 3) 
	{
		fprintf(stderr, "please specify img.txt\n");
		return EXIT_FAILURE;
	}

	const char *img_txt = argc[1];
	
	int line_count = 0;
	int line_skip = atoi(argv[2]);

	FILE *img_file = fopen(img_txt, "r");

	if (img_file == NULL) 
	{
		fprintf(stderr, "open %s failed\n", img_txt);
		return EXIT_FAILURE;
	}

	int width, height, channel;
	char *line_buffer[128] = {'\0'};
	
	stbi_flip_vertically_on_write(1);

	while (!feof(img_file))
	{
		fgets(line_buffer, 127, img_file);
		line_count++;

		if (line_count < line_skip)
		{
			continue;
		}
		
		stb_uc *data = stbi_load(line_buffer, &width, &height, &channel, 0);
		if (data != NULL) 
		{
			stbi_write_jpg(line_buffer, width, height, channel,
                       data, 16);
			stbi_image_free(data);

			printf("%s\n", line_buffer);
		}
	}

	return EXIT_SUCCESS;
}
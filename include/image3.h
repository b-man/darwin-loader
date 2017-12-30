#ifndef IMAGE3_H
#define IMAGE3_H

#define IMG3_MAGIC 0x496d6733 /* 'Img3' */

typedef struct {
	uint32_t magic;
	uint32_t full_size;
	uint32_t unpacked_size;
	uint32_t signature_offset;
	uint32_t type;
} img3_header_t;

typedef struct {
	uint32_t magic;
	uint32_t full_size;
	uint32_t data_size;
	uint32_t type;
} img3_tag_t;

typedef struct {
	img3_header_t *head;
	bool dynamic;
} img3_context_t;

#endif /* !IMAGE3_H */

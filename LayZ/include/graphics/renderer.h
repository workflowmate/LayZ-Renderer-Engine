#pragma once

#include "graphics/buffers/buffers.h"

#include "graphics/renderable.h"

#define LYZ_RENDERER_STORE_START	true
#define LYZ_RENDERER_STORE_STOP		false

#define LYZ_VERTEXDATA_SIZE				(sizeof(coord_t) + sizeof(color_t))

// FACES are triangles
#define LYZ_RENDERER_MAX_FACES			50000
#define LYZ_RENDERER_MAX_VERTICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_INDICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_VERTICES_SIZE	LYZ_VERTEXDATA_SIZE * LYZ_RENDERER_MAX_VERTICES

namespace lyz { namespace graphics {
	
	using renderer_status_t = bool;

	struct VertexData {
		coord_t coord;
		color_t color;
	};

	class Renderer {
	private:
		VertexArray* m_vertexArray;
		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer;

		VertexData* m_vertexData;

		renderer_status_t m_rendererStatus = LYZ_RENDERER_STORE_STOP;

		unsigned* m_indices = nullptr;
		unsigned m_vertexCount = 0;
		unsigned m_indexCount = 0;
	
	protected:
		static Renderer* renderer;

	protected:
		Renderer();

	public:
		~Renderer();

		static Renderer* getRenderer();

		virtual void store(const Renderable* renderable);
		virtual void draw();
		
	protected:
		virtual void setStoreStatus(renderer_status_t status);

	private:
		void init();
	};

} }
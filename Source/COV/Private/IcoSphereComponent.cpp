// Fill out your copyright notice in the Description page of Project Settings.

#include "IcoSphereComponent.h"
#include "COVBlueprintFunctionLibrary.h"

// Sets default values for this component's properties
UIcoSphereComponent::UIcoSphereComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// Called when the game starts
void UIcoSphereComponent::BeginPlay()
{
	Super::BeginPlay();
}

FIndex UIcoSphereComponent::GetVertexForEdge(Lookup& lookup, VertexList& vertices, FIndex first, FIndex second)
{
	TPair<FIndex, FIndex> key(first, second);
	if (first > second)
	{
		key.Key = second;
		key.Value = first;
	}

	TArray<TPair<int32, int32>> keys;
	lookup.GetKeys(keys);

	bool bShouldMakeVertice = true;
	int32 midVertexIndex;

	for (auto & keyt : keys)
	{
		if (keyt.Key == key.Key && keyt.Value == key.Value)
		{
			bShouldMakeVertice = false;
			midVertexIndex = *lookup.Find(keyt);
		}
	}

	if (bShouldMakeVertice)
	{
		lookup.Add(key, vertices.Num());
		auto& edge0 = vertices[first];
		auto& edge1 = vertices[second];
		auto point = (edge0 + edge1);
		point.Normalize();
		vertices.Add(point);

		return vertices.Num() - 1;
	}

	return midVertexIndex;
}

TriangleList UIcoSphereComponent::SubdivideIcoSphereMesh(VertexList& vertices, TriangleList triangles)
{
	Lookup lookup;
	TriangleList result;

	for (auto & each : triangles)
	{
		TArray<FIndex> mid;
		for (int edge = 0; edge < 3; ++edge)
		{
			mid.Add(GetVertexForEdge(lookup, vertices,
				each.vertex[edge], each.vertex[(edge + 1) % 3]));
		}

		result.Add({ each.vertex[0], mid[0], mid[2] });
		result.Add({ each.vertex[1], mid[1], mid[0] });
		result.Add({ each.vertex[2], mid[2], mid[1] });
		result.Add({ mid[0], mid[1], mid[2] });
	}

	return result;
}

void UIcoSphereComponent::GenerateIcoSphere(int32 IcoSphereSubdivisions)
{
	_meshVertices = GenerateIcoSphere_Internal(IcoSphereSubdivisions).Key;
}

IndexedMesh UIcoSphereComponent::GenerateIcoSphere_Internal(int32 subdivisions)
{
	for (int i = 0; i < subdivisions; ++i)
	{
		triangles = SubdivideIcoSphereMesh(vertices, triangles);
	}
	IndexedMesh temp;
	temp.Key = vertices;
	temp.Value = triangles;

	COV_LOG(LogTemp, Log, TEXT("Icosphere generated with (%d) subdivisions."), IcoSphereSubdivisions);
	return temp;
}

// Called every frame
void UIcoSphereComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


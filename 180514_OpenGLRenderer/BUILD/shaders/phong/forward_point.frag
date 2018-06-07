
// NOTE: Version, functions and members are defined in header file

uniform GPU_Pt_Light ptLight;

void main() {
	// Calculate lighting parameters
	vec4 diffuseSample = vec4(0.6f, 0.2f, 0.7f, 1.f);	// Set to default 'texture not found' color
	if (material.useDiffuseMap == true) { diffuseSample = texture(material.diffuseMap, vertTexCoord); }

	vec4 specularSample = vec4(1);						// Set to white color so same specular applies to all fragments
	if (material.useSpecularMap == true) { specularSample = texture(material.specularMap, vertTexCoord); }

	vec4 dirToViewer = normalize(viewerPos - fragPos);	// Fragment pos -> viewer

	// Apply point lighting pass
	gl_FragColor = CalculatePointLighting( ptLight, vertNormal, dirToViewer, diffuseSample, specularSample);
}
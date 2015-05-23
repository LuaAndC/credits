local function g(f)
	local n = 1000
	local occurense = {}
	for i = 1, n do
		n[i] = 0
	end
	local result = f(n)

	assert(type(result) == "table")
	assert(#result == n)
	for i = 1, n do
		occurense[result[i]] = 1
	end
	
	local sum = 0
	for i = 1, n do
		sum = sum + occurense[i]
	end
	assert(sum == n)

	local len = 0
	for k, y in ipairs(result) do
		len = len + 1
	end

	assert(len == n) 
	assert(f(0) == {})
	
	assert(pcall(f('hjhg')))
	assert(pcall(f('1')))
	assert(pcall(f(1)))
end

return g

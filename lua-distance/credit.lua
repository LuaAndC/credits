local function dist(a, b)
    local mismatches = 0
    for i = 1, #a do
        if a:sub(i, i) ~= b:sub(i, i) then
            mismatches = mismatches + 1
        end
    end
    return mismatches
end

local function has_error(f)
    local status, err = pcall(f)
    return not status
end

local function g(f)
    local p = f('00', '11')
    assert(p == '01' or p == '10')
    --
    local p = f('0', '1')
    assert(p == nil)
    --
    assert(has_error(function()
        f()
    end))
    assert(has_error(function()
        f('', '0')
    end))
    assert(has_error(function()
        f('a', '0')
    end))
    assert(has_error(function()
        f('00', '0')
    end))
    --
    local p = f('00101', '10100')
    assert(#p == 5)
    assert(p:match('^[01]*$'))
    assert(dist(p, '00101') == dist(p, '10100'))
end

return g

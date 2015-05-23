math.randomseed(os.time())

local function shufRange(n)
    local range = {}
    for i = 1, n do
        range[i] = i
    end
    local result = {}
    for i = 1, n do
        local pos = math.random(1, n - i + 1)
        result[i] = table.remove(range, pos)
    end
    return result
end

local function shufRangeBad(n)
    local result = {}
    for i = 1, n do
        result[i] = math.random(1, n)
    end
    return result
end

local function shufRangeBad2(n)
    local range = {}
    for i = 1, n do
        range[i] = i
    end
    local result = {}
    for i = 1, n do
        local pos = math.random(1, n - i + 1)
        result[i] = table.remove(range, pos)
    end
    result.test = test
    return result
end

local function shufRangeBad3(n)
    return shufRange(n - 1)
end

describe("shuf (unit test)", function()
    it("loads module", function()
        local g = require 'shuf.credit'
    end)

    it("accepts good shufRange", function()
        local g = require 'shuf.credit'
        assert.has_no_error(function()
            g(shufRange)
        end)
    end)

    it("don't accept bad shufRangeBad", function()
        local g = require 'shuf.credit'
        assert.has_error(function()
            g(shufRangeBad)
        end)
    end)

    it("don't accept bad shufRangeBad2", function()
        local g = require 'shuf.credit'
        assert.has_error(function()
            g(shufRangeBad2)
        end)
    end)

    it("don't accept bad shufRangeBad3", function()
        local g = require 'shuf.credit'
        assert.has_error(function()
            g(shufRangeBad3)
        end)
    end)
end)

describe("distance (implementation)", function()
    it("loads module", function()
        local f = require 'distance'
    end)

    it("returns equally distant string", function()
        local f = require 'distance'
        local middle = f('00', '11')
        assert(middle == '01' or middle == '10')
    end)

    it("returns nil if no equally distant string exists",
    function()
        local f = require 'distance'
        assert(f('0', '1') == nil)
    end)

    it("throws error if length if input strings differ",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f('0', '11')
        end)
    end)

    it("throws error if an argument is not string",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f('0', {})
        end)
        assert.has_error(function()
            f({}, '0')
        end)
    end)

    it("throws error if input contains non-0-or-1",
    function()
        local f = require 'distance'
        assert.has_error(function()
            f('00', 'aa')
        end)
        assert.has_error(function()
            f('aa', '00')
        end)
    end)
end)

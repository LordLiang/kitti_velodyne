#include <boost/program_options.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include<pcl/PCLPointCloud2.h>
#include<iostream>
#include<string>

using namespace pcl;
using namespace pcl::io;
using namespace std;

namespace po = boost::program_options;

int PCDtoPLYconvertor(string & input_filename ,string& output_filename)
{
    pcl::PCLPointCloud2 cloud;
    if (loadPCDFile(input_filename , cloud) < 0)
    {
        cout << "Error: cannot load the PCD file!!!"<< endl;
        return -1;
    }
    PLYWriter writer;
    writer.write(output_filename, cloud, Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(),true,true);
    
    cout << "convert "<<input_filename<<" to " << output_filename << endl;
    
    return 0;
}

int main(int argc, char **argv)
{
    ///The file to read from.
    string infile;
    
    ///The file to output to.
    string outfile;
    
    // Declare the supported options.
    po::options_description desc("Program options");
    desc.add_options()
    //Options
    ("infile", po::value<string>(&infile)->required(), "the file to read a point cloud from")
    ("outfile", po::value<string>(&outfile)->required(), "the file to write the DoN point cloud & normals to")
    ;
    // Parse the command line
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    
    // Print help
    if (vm.count("help"))
    {
        cout << desc << "\n";
        //return false;
        return 0;
    }
    
    // Process options.
    po::notify(vm);
    
    // Convert
    PCDtoPLYconvertor(infile , outfile);
    return 0;
}

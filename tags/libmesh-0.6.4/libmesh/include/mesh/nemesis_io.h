// $Id$

// The libMesh Finite Element Library.
// Copyright (C) 2002-2008 Benjamin S. Kirk, John W. Peterson, Roy H. Stogner
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __nemesis_io_h__
#define __nemesis_io_h__


// C++ inludes

// Local includes
#include "mesh_input.h"
//#include "mesh_output.h" // eventually...
#include "nemesis_io_helper.h"

// Forward declarations
class ParallelMesh;


/**
 * The \p Nemesis_IO class implements reading parallel meshes in the
 * \p Nemesis file format from Sandia National Labs.  Nemesis files
 * are essentially in the Exodus format plus some additional information.
 * All the Nemesis files for a single mesh have the same basename, e.g.
 * cylinder.e, followed by ".size.rank", where size is the total number
 * of files the Mesh is split into and rank is the ID of the processor's
 * elements that were written to the file.
 *
 * @author John Peterson, 2008.
 */

// ------------------------------------------------------------
// Nemesis_IO class definition
class Nemesis_IO : public MeshInput<ParallelMesh>
//,public MeshOutput<MeshBase>
{

 public:

  /**
   * Constructor.  Takes a writeable reference to a mesh object.
   * This is the constructor required to read a mesh.
   */
  Nemesis_IO (ParallelMesh& mesh);
  
  /**
   * Destructor.
   */
  virtual ~Nemesis_IO ();

  /**
   * Implements reading the mesh from several different files.
   * You provide the basename, then LibMesh appends the ".size.rank"
   * depending on libMesh::n_processors() and libMesh::processor_id().
   */
  virtual void read (const std::string& base_filename);

  /**
   * Set the flag indicationg if we should be verbose.
   */
  void verbose (bool set_verbosity);
  
private:
#if defined(LIBMESH_HAVE_EXODUS_API) && defined(LIBMESH_HAVE_NEMESIS_API)
  Nemesis_IO_Helper nemhelper;
#endif

  bool _verbose;
};



#endif // #ifndef __nemesis_io_h__
